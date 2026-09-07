// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_speechfilter.cpp
// Functions: 24
// ============================================================

#include "game\server\ai_speechfilter.h"

//------------------------------------------------------------------------------
// Address: 0x1008A230
// Name: public: virtual struct datamap_t __near * CAI_SpeechFilter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_SpeechFilter::GetDataDescMap(CAI_SpeechFilter *this)
{
  return &CAI_SpeechFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1008A240
// Name: public: virtual void CAI_SpeechFilter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::Spawn(CAI_SpeechFilter *this)
{
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  if ( this != nullptr )
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
  else
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1008A270
// Name: public: virtual void CAI_SpeechFilter::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::UpdateOnRemove(CAI_SpeechFilter *this)
{
  if ( this != nullptr )
  {
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
    CBaseEntity::UpdateOnRemove(this);
  }
  else
  {
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: nullptr);
    CBaseEntity::UpdateOnRemove(this: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A2B0
// Name: public: void CAI_SpeechFilter::InputSetIdleModifier(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::InputSetIdleModifier(CAI_SpeechFilter *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flIdleModifier) = inputdata->value.iVal;
  else
    this->m_flIdleModifier = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1008A2E0
// Name: public: void CAI_SpeechFilter::PopulateSubjectList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::PopulateSubjectList(CAI_SpeechFilter *this, bool purge)
{
  CBaseEntity *EntityByName; // eax
  int i; // edi
  const char *pszValue; // ecx
  const char *v6; // ecx
  const char *v7; // eax

  EntityByName = nullptr;
  for ( i = 0; ; ++i )
  {
    pszValue = this->m_iszSubject.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      break;
  }
  if ( i == 0 )
  {
    while ( 1 )
    {
      v6 = this->m_iszSubject.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      EntityByName = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: EntityByName, szName: v6);
      if ( EntityByName == nullptr )
        break;
      ++i;
    }
    if ( i == 0 )
    {
      v7 = this->m_iszSubject.pszValue;
      if ( v7 == nullptr )
        v7 = locale;
      _DevMsg(a1: 2, a2: "ai_speechfilter finds no subject(s) called: %s\n", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A370
// Name: public: virtual void CAI_SpeechFilter::OnEntityCreated(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::OnEntityCreated(CAI_SpeechFilter *this, CBaseEntity *pEntity)
{
  const char *m_pfnMoveDone; // eax
  const char *v4; // eax

  if ( BYTE1(this->m_Network.CBaseEntity::__vftable) != 0 )
    goto LABEL_6;
  m_pfnMoveDone = (const char *)this->m_pfnMoveDone;
  if ( pEntity->m_iName.m_Value.pszValue != m_pfnMoveDone )
  {
    if ( m_pfnMoveDone == nullptr )
      m_pfnMoveDone = locale;
    if ( CBaseEntity::NameMatchesComplex(this: pEntity, pszNameOrWildcard: m_pfnMoveDone) == 0 )
    {
LABEL_6:
      v4 = (const char *)this->m_pfnMoveDone;
      if ( pEntity->m_iClassname.pszValue != v4 )
      {
        if ( v4 == nullptr )
          v4 = locale;
        CBaseEntity::ClassMatchesComplex(this: pEntity, pszClassOrWildcard: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A3C0
// Name: public: virtual void CAI_SpeechFilter::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::Activate(CAI_SpeechFilter *this)
{
  CBaseEntity::Activate(this);
  CAI_SpeechFilter::PopulateSubjectList(this, purge: this->m_bDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3E0
// Name: public: void CAI_SpeechFilter::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::InputEnable(CAI_SpeechFilter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
  CAI_SpeechFilter::PopulateSubjectList(this, purge: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008A400
// Name: public: void CAI_SpeechFilter::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SpeechFilter::InputDisable(CAI_SpeechFilter *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
  CAI_SpeechFilter::PopulateSubjectList(this, purge: true);
}

//------------------------------------------------------------------------------
// Address: 0x103FEDA0
// Name: CAI_SpeechFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_SpeechFilter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_SpeechFilter>();
  CAI_SpeechFilter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402FF0
// Name: _dynamic_initializer_for__filter_base__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_base__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseFilter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_base,
           a3: "filter_base");
}

//------------------------------------------------------------------------------
// Address: 0x10403020
// Name: _dynamic_initializer_for__filter_multi__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_multi__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterMultiple> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_multi,
           a3: "filter_multi");
}

//------------------------------------------------------------------------------
// Address: 0x10403050
// Name: _dynamic_initializer_for__filter_activator_name__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_name__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterName> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_name,
           a3: "filter_activator_name");
}

//------------------------------------------------------------------------------
// Address: 0x10403080
// Name: _dynamic_initializer_for__filter_activator_model__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_model__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterModel> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_model,
           a3: "filter_activator_model");
}

//------------------------------------------------------------------------------
// Address: 0x104030B0
// Name: _dynamic_initializer_for__filter_activator_context__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_context__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterContext> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_context,
           a3: "filter_activator_context");
}

//------------------------------------------------------------------------------
// Address: 0x104030E0
// Name: _dynamic_initializer_for__filter_activator_class__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_class__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterClass> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_class,
           a3: "filter_activator_class");
}

//------------------------------------------------------------------------------
// Address: 0x10403110
// Name: _dynamic_initializer_for__filter_activator_team__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_team__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<FilterTeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_team,
           a3: "filter_activator_team");
}

//------------------------------------------------------------------------------
// Address: 0x10403140
// Name: _dynamic_initializer_for__filter_activator_mass_greater__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_activator_mass_greater__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterMassGreater> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_activator_mass_greater,
           a3: "filter_activator_mass_greater");
}

//------------------------------------------------------------------------------
// Address: 0x10403170
// Name: _dynamic_initializer_for__filter_damage_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_damage_type__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<FilterDamageType> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_damage_type,
           a3: "filter_damage_type");
}

//------------------------------------------------------------------------------
// Address: 0x104031A0
// Name: _dynamic_initializer_for__filter_enemy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__filter_enemy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFilterEnemy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &filter_enemy,
           a3: "filter_enemy");
}

//------------------------------------------------------------------------------
// Address: 0x1008A420
// Name: class CAI_SpeechFilter __near * _CreateEntityTemplate<class CAI_SpeechFilter>(class CAI_SpeechFilter __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_SpeechFilter *__cdecl _CreateEntityTemplate<CAI_SpeechFilter>(CAI_SpeechFilter *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[213] = &IEntityListener::`vftable';
    *v3 = &CAI_SpeechFilter::`vftable'{for `CBaseEntity'};
    v3[213] = &CAI_SpeechFilter::`vftable'{for `IEntityListener'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAI_SpeechFilter *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FEDB0
// Name: _dynamic_initializer_for__rr_followup_maxdist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_followup_maxdist__()
{
  ConVar::ConVar(
    this: &rr_followup_maxdist,
    pName: "rr_followup_maxdist",
    pDefaultValue: "1800",
    flags: 0x4000,
    pHelpString: "'then ANY' or 'then ALL' response followups will be dispatched only to characters within this distance.");
  return atexit(func: dynamic_atexit_destructor_for__rr_followup_maxdist__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEDE0
// Name: _dynamic_initializer_for__rr_thenany_score_slop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_thenany_score_slop__()
{
  ConVar::ConVar(
    this: &rr_thenany_score_slop,
    pName: "rr_thenany_score_slop",
    pDefaultValue: "0.0",
    flags: 16512,
    pHelpString: "When computing respondents for a 'THEN ANY' rule, all rule-matching scores within this much of the best score will be considered.");
  return atexit(func: dynamic_atexit_destructor_for__rr_thenany_score_slop__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEE10
// Name: _dynamic_initializer_for__g_ResponseQueueManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ResponseQueueManager__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_ResponseQueueManager, name: "CResponseQueueManager");
  g_ResponseQueueManager.__vftable = (CResponseQueueManager_vtbl *)&CResponseQueueManager::`vftable';
  g_ResponseQueueManager.m_pQueue = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_ResponseQueueManager__);
}
