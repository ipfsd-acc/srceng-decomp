// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/flex_expresser.cpp
// Functions: 36
// ============================================================

#include "game\server\flex_expresser.h"

//------------------------------------------------------------------------------
// Address: 0x1012A7F0
// Name: public: virtual void CFlexExpresser::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexExpresser::Think(CFlexExpresser *this)
{
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  this->StudioFrameAdvance(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012A820
// Name: public: virtual struct datamap_t __near * CFlexExpresser::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFlexExpresser::GetDataDescMap(CFlexExpresser *this)
{
  return &CFlexExpresser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012A8D0
// Name: protected: class CAI_Expresser __near * CFlexExpresser::CreateExpresser(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Expresser *__thiscall CFlexExpresser::CreateExpresser(CFlexExpresser *this)
{
  CAI_Expresser *v2; // eax
  CAI_Expresser *v3; // esi

  v2 = (CAI_Expresser *)operator new(nSize: 0x50u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CAI_Expresser::CAI_Expresser(this: v2, pOuter: this);
    v3->__vftable = (CAI_Expresser_vtbl *)&CAI_ExpresserWithFollowup::`vftable';
    v3[1].__vftable = nullptr;
    v3[1].m_pSink = (CAI_ExpresserSink *)3;
    v3[1].m_ConceptHistories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))-1;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_pExpresser = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->m_pSink = &this->CAI_ExpresserSink;
  return this->m_pExpresser;
}

//------------------------------------------------------------------------------
// Address: 0x1012A930
// Name: public: static class CFlexExpresser __near * CFlexExpresser::AsFlexExpresser(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CFlexExpresser *__cdecl CFlexExpresser::AsFlexExpresser(CBaseEntity *pEntity)
{
  if ( pEntity != nullptr
    && (pEntity->m_iClassname.pszValue == "prop_talker"
     || CBaseEntity::ClassMatchesComplex(this: pEntity, pszClassOrWildcard: "prop_talker") != 0) )
  {
    return (CFlexExpresser *)pEntity;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AA10
// Name: public: void CFlexExpresser::InputSpeakResponseConcept(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexExpresser::InputSpeakResponseConcept(CFlexExpresser *this, inputdata_t *inputdata)
{
  bool v2; // zf
  variant_t *p_value; // eax
  CFlexExpresser *v4; // edi
  const char *iVal; // eax
  int v6; // esi
  const char *v7; // eax
  char *v8; // ebx
  const char *v9; // eax
  const char *v10; // edi
  unsigned int v11; // eax
  CBaseEntity *pActivator; // edx
  CBaseEntity *v13; // eax
  unsigned int v14; // esi
  const char *v15; // edi
  CBasePlayer *EntityProcedural; // eax
  const char *pszValue; // eax
  const char *v18; // edx
  signed int v19; // edi
  const char *DebugName; // eax
  CBaseEntity *v21; // eax
  CBaseEntity *v22; // ecx
  const char *v23; // eax
  int v24; // [esp-18h] [ebp-430h] BYREF
  char *v25; // [esp-10h] [ebp-428h]
  int v26; // [esp-Ch] [ebp-424h]
  CBaseEntity *v27; // [esp-8h] [ebp-420h]
  CBaseEntity *pCaller; // [esp-4h] [ebp-41Ch]
  char buf[512]; // [esp+Ch] [ebp-40Ch] BYREF
  char outputmodifiers[512]; // [esp+20Ch] [ebp-20Ch] BYREF
  unsigned int v31; // [esp+40Ch] [ebp-Ch]
  CBaseEntity *v32; // [esp+410h] [ebp-8h] BYREF
  CBaseEntity *pSearchingEntity; // [esp+414h] [ebp-4h]

  v2 = inputdata->value.fieldType == FIELD_STRING;
  p_value = &inputdata->value;
  v4 = this;
  pSearchingEntity = this;
  if ( !v2 )
  {
    v32 = nullptr;
    p_value = (variant_t *)&v32;
  }
  iVal = (const char *)p_value->iVal;
  v32 = (CBaseEntity *)iVal;
  if ( iVal != nullptr && *iVal != 0 )
  {
    v6 = 0;
    V_strncpy(pDest: buf, pSrc: iVal, maxLen: 510);
    buf[511] = 0;
    v7 = V_strnchr(pStr: buf, c: 32, n: 510);
    if ( v7 != nullptr && (*v7 = 0, (v8 = strtok(string: (char *)v7 + 1, control: " ")) != nullptr) )
    {
      while ( 1 )
      {
        v9 = V_strnchr(pStr: v8, c: 58, n: 510);
        v10 = v9;
        if ( v9 == nullptr )
        {
          _Warning(a1: "faulty context k:v pair in entity io %s\n", (const char *)v32);
LABEL_20:
          v4 = (CFlexExpresser *)pSearchingEntity;
          goto LABEL_21;
        }
        v11 = v9 - v8 + 1;
        v31 = v11 + v6;
        if ( (int)(v11 + v6) >= 512 )
          break;
        memcpy(dst: (unsigned __int8 *)&outputmodifiers[v6], src: (unsigned __int8 *)v8, count: v11);
        pActivator = inputdata->pActivator;
        v13 = pSearchingEntity;
        v14 = v31;
        pCaller = inputdata->pCaller;
        v27 = pActivator;
        *v10 = 0;
        v15 = v10 + 1;
        EntityProcedural = CGlobalEntityList::FindEntityProcedural(
                             this: &gEntList,
                             szName: v15,
                             pSearchingEntity: v13,
                             pActivator: v27,
                             pCaller);
        if ( EntityProcedural != nullptr )
        {
          pszValue = EntityProcedural->m_iName.m_Value.pszValue;
          if ( pszValue != nullptr )
            v18 = pszValue;
          else
            v18 = locale;
        }
        else
        {
          v18 = v15;
        }
        v19 = strlen(v18);
        if ( (int)(511 - v14) < v19 )
          v19 = 511 - v14;
        V_strncpy(pDest: &outputmodifiers[v14], pSrc: v18, maxLen: v19 + 1);
        v6 = v19 + v14;
        v8 = strtok(string: nullptr, control: " ");
        if ( v8 == nullptr )
          goto LABEL_20;
        if ( v6 < 511 )
          outputmodifiers[v6++] = 44;
      }
      pCaller = v32;
      DebugName = CBaseEntity::GetDebugName(this: pSearchingEntity);
      _Warning(a1: "Speak input to %s had overlong parameter %s", DebugName, (const char *)pCaller);
    }
    else
    {
LABEL_21:
      pCaller = nullptr;
      v27 = nullptr;
      v26 = 0;
      outputmodifiers[v6] = 0;
      v25 = v6 <= 0 ? nullptr : outputmodifiers;
      ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)&v24, fromString: buf);
      ((void (__thiscall *)(CFlexExpresser *, int, int, char *, int, CBaseEntity *, CBaseEntity *))v4->Speak)(
        a1: v4,
        a2: v24,
        a3: -1,
        a4: v25,
        a5: v26,
        a6: v27,
        a7: pCaller);
    }
  }
  else
  {
    v21 = (CBaseEntity *)CBaseEntity::GetDebugName(this);
    v22 = inputdata->pCaller;
    pCaller = v21;
    v23 = CBaseEntity::GetDebugName(this: v22);
    _Warning(a1: "empty SpeakResponse input from %s to %s\n", v23, (const char *)pCaller);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AD10
// Name: public: virtual void CFlexExpresser::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlexExpresser::Spawn(CFlexExpresser *this)
{
  bool (__cdecl *v2)(const char *); // edi
  const char *DebugName; // eax
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  edict_t *m_pPev; // ecx
  double x; // [esp+4h] [ebp-24h]
  double y; // [esp+Ch] [ebp-1Ch]
  double thinkTime_4; // [esp+14h] [ebp-14h]
  _BYTE v9[4]; // [esp+24h] [ebp-4h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v2 = *(bool (__cdecl **)(const char *))((int (__thiscall *)(CFlexExpresser *, _BYTE *))this->GetModelName)(
                                           a1: this,
                                           a2: v9);
  if ( v2 != nullptr && *(_BYTE *)v2 != 0 )
  {
    CBaseEntity::PrecacheModel(a1: v2, name: (const char *)v2, bPreload: true);
    this->SetModel(this, a2: (const char *)v2);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    thinkTime_4 = this->m_vecAbsOrigin.z;
    y = this->m_vecAbsOrigin.y;
    x = this->m_vecAbsOrigin.x;
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "WARNING: %s at %.0f %.0f %0.f missing modelname\n", DebugName, x, y, thinkTime_4);
  }
  this->Precache(this);
  p_m_Collision = &this->m_Collision;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_NONE);
  }
  else
  {
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_BBOX);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  if ( this->m_iHealth.m_Value != 80000 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 80000;
  }
  if ( this->m_flPlaybackRate.m_Value != 1.0 )
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
    this->m_flPlaybackRate.m_Value = 1.0;
  }
  this->m_flGroundSpeed = 0.0;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
  CBaseAnimating::ResetSequenceInfo(this);
  this->InitBoneControllers(this);
  CFlexExpresser::CreateExpresser(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FA7B0
// Name: _dynamic_initializer_for__flex_minplayertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_minplayertime__()
{
  ConVar::ConVar(this: &flex_minplayertime, pName: "flex_minplayertime", pDefaultValue: "5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_minplayertime__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA7E0
// Name: _dynamic_initializer_for__flex_maxplayertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_maxplayertime__()
{
  ConVar::ConVar(this: &flex_maxplayertime, pName: "flex_maxplayertime", pDefaultValue: "7", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_maxplayertime__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA810
// Name: _dynamic_initializer_for__flex_minawaytime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_minawaytime__()
{
  ConVar::ConVar(this: &flex_minawaytime, pName: "flex_minawaytime", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_minawaytime__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA840
// Name: _dynamic_initializer_for__flex_maxawaytime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_maxawaytime__()
{
  ConVar::ConVar(this: &flex_maxawaytime, pName: "flex_maxawaytime", pDefaultValue: "1.0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_maxawaytime__);
}

//------------------------------------------------------------------------------
// Address: 0x104003F0
// Name: _dynamic_initializer_for__flex_expression__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_expression__()
{
  ConVar::ConVar(this: &flex_expression, pName: "flex_expression", pDefaultValue: "-", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_expression__);
}

//------------------------------------------------------------------------------
// Address: 0x10400420
// Name: _dynamic_initializer_for__flex_talk__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_talk__()
{
  ConVar::ConVar(this: &flex_talk, pName: "flex_talk", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_talk__);
}

//------------------------------------------------------------------------------
// Address: 0x104035B0
// Name: CFlexExpresser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFlexExpresser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFlexExpresser>();
  CFlexExpresser_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404E10
// Name: _dynamic_initializer_for__flex_looktime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flex_looktime__()
{
  ConVar::ConVar(this: &flex_looktime, pName: "flex_looktime", pDefaultValue: "5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__flex_looktime__);
}

//------------------------------------------------------------------------------
// Address: 0x10418840
// Name: _dynamic_atexit_destructor_for__flex_minplayertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_minplayertime__()
{
  ConVar::~ConVar(this: &flex_minplayertime);
}

//------------------------------------------------------------------------------
// Address: 0x10418850
// Name: _dynamic_atexit_destructor_for__flex_maxplayertime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_maxplayertime__()
{
  ConVar::~ConVar(this: &flex_maxplayertime);
}

//------------------------------------------------------------------------------
// Address: 0x10418860
// Name: _dynamic_atexit_destructor_for__flex_minawaytime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_minawaytime__()
{
  ConVar::~ConVar(this: &flex_minawaytime);
}

//------------------------------------------------------------------------------
// Address: 0x10418870
// Name: _dynamic_atexit_destructor_for__flex_maxawaytime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_maxawaytime__()
{
  ConVar::~ConVar(this: &flex_maxawaytime);
}

//------------------------------------------------------------------------------
// Address: 0x10419E10
// Name: _dynamic_atexit_destructor_for__flex_expression__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_expression__()
{
  ConVar::~ConVar(this: &flex_expression);
}

//------------------------------------------------------------------------------
// Address: 0x10419E20
// Name: _dynamic_atexit_destructor_for__flex_talk__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_talk__()
{
  ConVar::~ConVar(this: &flex_talk);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE50
// Name: _dynamic_atexit_destructor_for__flex_looktime__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__flex_looktime__()
{
  ConVar::~ConVar(this: &flex_looktime);
}

//------------------------------------------------------------------------------
// Address: 0x103FA870
// Name: _dynamic_initializer_for__ai_debug_looktargets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_looktargets__()
{
  ConVar::ConVar(this: &ai_debug_looktargets, pName: "ai_debug_looktargets", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_looktargets__);
}

//------------------------------------------------------------------------------
// Address: 0x103FA8A0
// Name: _dynamic_initializer_for__ai_debug_expressions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_expressions__()
{
  ConVar::ConVar(
    this: &ai_debug_expressions,
    pName: "ai_debug_expressions",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show random expression decisions for NPCs.");
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_expressions__);
}

//------------------------------------------------------------------------------
// Address: 0x10418880
// Name: _dynamic_atexit_destructor_for__ai_debug_looktargets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_looktargets__()
{
  ConVar::~ConVar(this: &ai_debug_looktargets);
}

//------------------------------------------------------------------------------
// Address: 0x10418890
// Name: _dynamic_atexit_destructor_for__ai_debug_expressions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ai_debug_expressions__()
{
  ConVar::~ConVar(this: &ai_debug_expressions);
}

//------------------------------------------------------------------------------
// Address: 0x10419E30
// Name: _ServerClassInit_DT_BaseFlex::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseFlex::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_50;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419E50
// Name: _dynamic_atexit_destructor_for__g_FlexSceneFileManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FlexSceneFileManager__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_FlexSceneFileManager.m_FileList);
  IGameSystem::~IGameSystem(this: &g_FlexSceneFileManager);
}

//------------------------------------------------------------------------------
// Address: 0x10419E70
// Name: _DataMapInit_CFlexCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFlexCycler__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_92);
}

//------------------------------------------------------------------------------
// Address: 0x10419E80
// Name: _DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexsettinghdr_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_93);
}

//------------------------------------------------------------------------------
// Address: 0x10419E90
// Name: _DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexsetting_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_94);
}

//------------------------------------------------------------------------------
// Address: 0x10419EA0
// Name: _DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_flexweight_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_95);
}

//------------------------------------------------------------------------------
// Address: 0x10419EB0
// Name: _DataMapInit_CBaseFlex__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseFlex__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_96);
}

//------------------------------------------------------------------------------
// Address: 0x10419EC0
// Name: _dynamic_atexit_destructor_for__g_CBaseFlex_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CBaseFlex_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CBaseFlex_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE60
// Name: _DataMapInit_CGenericActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGenericActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_227);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE70
// Name: _DataMapInit_CFlextalkActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFlextalkActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_228);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE80
// Name: _DataMapInit_CNPC_Furniture__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CNPC_Furniture__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_229);
}
