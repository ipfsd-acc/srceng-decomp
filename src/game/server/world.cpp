// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/world.cpp
// Functions: 50
// ============================================================

#include "game\server\world.h"

//------------------------------------------------------------------------------
// Address: 0x101157B0
// Name: public: void CInfoGameEventProxy::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoGameEventProxy::InputDisable(CEnvPlayerSurfaceTrigger *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x101157C0
// Name: public: void CInfoGameEventProxy::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoGameEventProxy::InputEnable(CEnvPlayerSurfaceTrigger *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x102670F0
// Name: public: static bool CInfoGameEventProxy::GameEventProxyEvaluator(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CInfoGameEventProxy::GameEventProxyEvaluator(CBaseEntity *pProxy)
{
  return pProxy != nullptr && LOBYTE(pProxy[1].m_pfnThink) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10267110
// Name: public: virtual struct datamap_t __near * CInfoGameEventProxy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoGameEventProxy::GetDataDescMap(CInfoGameEventProxy *this)
{
  return &CInfoGameEventProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10267120
// Name: public: virtual struct datamap_t __near * CDecal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDecal::GetDataDescMap(CDecal *this)
{
  return &CDecal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10267130
// Name: public: virtual struct datamap_t __near * CProjectedDecal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CProjectedDecal::GetDataDescMap(CProjectedDecal *this)
{
  return &CProjectedDecal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10267140
// Name: private: virtual struct datamap_t __near * CWorld::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWorld::GetDataDescMap(CWorld *this)
{
  return &CWorld::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10267150
// Name: public: virtual class ServerClass __near * CWorld::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CWorld::GetServerClass(CWorld *this)
{
  return &g_CWorld_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10267160
// Name: class CWorld __near * GetWorldEntity(void)
// Source: json
//------------------------------------------------------------------------------
CWorld *__cdecl GetWorldEntity()
{
  return g_WorldEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10267170
// Name: public: virtual CWorld::~CWorld(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::~CWorld(CWorld *this)
{
  this->__vftable = (CWorld_vtbl *)&CWorld::`vftable';
  Editor_EndSession(bShowUI: false);
  EventList_Free();
  ActivityList_Free();
  if ( g_pGameRules != nullptr )
  {
    g_pGameRules->LevelShutdown(this: g_pGameRules);
    if ( g_pGameRules != nullptr )
      ((void (__thiscall *)(CGameRules *, int))g_pGameRules->dtr_IGameSystem)(a1: g_pGameRules, a2: 1);
    g_pGameRules = nullptr;
  }
  g_WorldEntity = nullptr;
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x102671E0
// Name: char const __near * GetDefaultLightstyleString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetDefaultLightstyleString(unsigned int styleIndex)
{
  if ( styleIndex >= 0xD )
    return "m";
  else
    return g_DefaultLightstyles[styleIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10267200
// Name: public: virtual void CWorld::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CWorld::UpdateOnRemove(CBreakableProp *this)
{
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10267210
// Name: public: bool CWorld::GetDisplayTitle(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorld::GetDisplayTitle(CAI_ScriptedSequence *this)
{
  return this->m_bWaitForBeginSequence;
}

//------------------------------------------------------------------------------
// Address: 0x10267220
// Name: public: void CWorld::SetDisplayTitle(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::SetDisplayTitle(CWorld *this, bool display)
{
  this->m_bDisplayTitle = display;
}

//------------------------------------------------------------------------------
// Address: 0x10267230
// Name: private: void CProjectedDecal::ProjectDecal(class CRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProjectedDecal::ProjectDecal(CProjectedDecal *this, CRecipientFilter *filter)
{
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ((void (__stdcall *)(CRecipientFilter *, _DWORD, Vector *, QAngle *, _DWORD, int))te->ProjectDecal)(
    a1: filter,
    a2: 0,
    a3: &this->m_vecAbsOrigin,
    a4: &this->m_angAbsRotation,
    a5: LODWORD(this->m_flDistance),
    a6: this->m_nTexture);
}

//------------------------------------------------------------------------------
// Address: 0x102672A0
// Name: public: void CProjectedDecal::TriggerDecal(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProjectedDecal::TriggerDecal(
        CProjectedDecal *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CBroadcastRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  CProjectedDecal::ProjectDecal(this, &filter);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10267320
// Name: private: void CProjectedDecal::StaticDecal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProjectedDecal::StaticDecal(CProjectedDecal *this)
{
  CBroadcastRecipientFilter initFilter; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &initFilter);
  initFilter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &initFilter);
  CRecipientFilter::MakeInitMessage(this: &initFilter);
  CProjectedDecal::ProjectDecal(this, filter: &initFilter);
  CBaseEntity::SUB_Remove(this);
  CRecipientFilter::~CRecipientFilter(this: &initFilter);
}

//------------------------------------------------------------------------------
// Address: 0x10267370
// Name: public: virtual bool CDecal::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDecal::KeyValue(CProjectedDecal *this, const char *szKeyName, const char *szValue)
{
  int v4; // eax

  if ( szKeyName != "texture" && _V_stricmp(s1: szKeyName, s2: "texture") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  v4 = UTIL_PrecacheDecal(name: szValue, preload: true);
  this->m_nTexture = v4;
  if ( v4 < 0 )
    _Warning(a1: "Can't find decal %s\n", szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10267410
// Name: public: virtual void CWorld::DecalTrace(class CGameTrace __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::DecalTrace(CWorld *this, CGameTrace *pTrace, const char *decalName)
{
  int v3; // esi
  int hitbox; // edx
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-20h] BYREF

  v3 = decalsystem->GetDecalIndexForName(this: decalsystem, a2: decalName);
  if ( v3 >= 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    CRecipientFilter::AddAllPlayers(this: &filter);
    hitbox = pTrace->hitbox;
    if ( hitbox != 0 )
      ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, Vector *, CGameTrace *, _DWORD, int, int))te->Decal)(
        a1: &filter,
        a2: 0,
        a3: &pTrace->endpos,
        a4: pTrace,
        a5: 0,
        a6: hitbox,
        a7: v3);
    else
      ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, Vector *, int))te->WorldDecal)(
        a1: &filter,
        a2: 0,
        a3: &pTrace->endpos,
        a4: v3);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102674B0
// Name: public: virtual void CWorld::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::Spawn(CWorld *this)
{
  IVModelInfo_vtbl *v2; // edi
  model_t *Model; // eax
  const char *v4; // eax
  const char *v5; // eax
  char pszValue[4]; // [esp+8h] [ebp-4h] BYREF

  CBaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
  this->SetModelIndex(this, a2: 1);
  v2 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this);
  v2->GetModelName(this: modelinfo, a2: Model);
  this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CBaseEntity::AddFlag(this, flags: 0x2000000);
  CEventQueue::Init(this: &g_EventQueue);
  this->Precache(this);
  v4 = gpGlobals->mapname.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  GlobalEntity_Add(pGlobalname: "is_console", pMapName: v4, state: GLOBAL_OFF);
  v5 = gpGlobals->mapname.pszValue;
  if ( v5 == nullptr )
    v5 = locale;
  GlobalEntity_Add(pGlobalname: "is_pc", pMapName: v5, state: GLOBAL_ON);
}

//------------------------------------------------------------------------------
// Address: 0x10267580
// Name: public: void CInfoGameEventProxy::InputGenerateGameEvent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoGameEventProxy::InputGenerateGameEvent(CInfoGameEventProxy *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // esi
  CBaseEntity *v4; // edi
  const char *pszValue; // eax
  IGameEvent *v6; // esi
  int v7; // eax
  edict_t *m_pPev; // eax

  pActivator = inputdata->pActivator;
  if ( inputdata->pActivator != nullptr && pActivator->IsPlayer(this: inputdata->pActivator) )
    v4 = pActivator;
  else
    v4 = nullptr;
  pszValue = this->m_iszEventName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: pszValue, a3: 0, a4: 0);
  if ( v6 != nullptr )
  {
    if ( v4 != nullptr )
    {
      v7 = engine->GetPlayerUserId(this: engine, a2: v4->m_Network.m_pPev);
      v6->SetInt(this: v6, a2: "userid", a3: v7);
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v6->SetInt(this: v6, a2: "subject", a3: (int)m_pPev);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10267630
// Name: public: static bool CInfoGameEventProxy::GameEventProxyCallback(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CInfoGameEventProxy::GameEventProxyCallback@<al>(
        int a1@<esi>,
        CBaseEntity *pProxy,
        CBasePlayer *pViewingPlayer)
{
  const char *v4; // eax
  IGameEvent *v5; // esi
  int v6; // eax

  if ( pProxy == nullptr )
    return 1;
  v4 = (const char *)pProxy[1].__vftable;
  if ( v4 == nullptr )
    v4 = locale;
  v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: v4, a3: 0, a4: 0);
  if ( v5 != nullptr )
  {
    v6 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
           a1: engine,
           a2: pViewingPlayer->m_Network.m_pPev,
           a3: a1);
    v5->SetInt(this: v5, a2: "userid", a3: v6);
    ((void (__thiscall *)(IGameEvent *, const char *))v5->SetInt)(a1: v5, a2: "subject");
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102676D0
// Name: public: virtual void CDecal::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecal::Spawn(CProjectedDecal *this)
{
  if ( this->m_nTexture < 0 || gpGlobals->deathmatch && (this->m_spawnflags.m_Value & 0x800) != 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10267700
// Name: public: virtual bool CTraceFilterValidForDecal::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterValidForDecal::ShouldHitEntity(
        CTraceFilterValidForDecal *this,
        IHandleEntity *pServerEntity,
        int contentsMask)
{
  CBaseEntity *v3; // esi
  unsigned int i; // edi
  IVModelInfo_vtbl *v6; // edi
  model_t *Model; // eax

  if ( staticpropmgr->IsStaticProp_2(this: staticpropmgr, a2: pServerEntity) )
    v3 = nullptr;
  else
    v3 = (CBaseEntity *)pServerEntity->__vftable[1].GetRefEHandle(this: pServerEntity);
  if ( (v3->m_fEffects.m_Value & 0x20) != 0 )
    return 0;
  for ( i = 0; i < 7; ++i )
  {
    if ( v3->m_iClassname.pszValue == `CTraceFilterValidForDecal::ShouldHitEntity'::`2'::ppszIgnoredClasses[i]
      || CBaseEntity::ClassMatchesComplex(
           this: v3,
           pszClassOrWildcard: `CTraceFilterValidForDecal::ShouldHitEntity'::`2'::ppszIgnoredClasses[i]) != 0 )
    {
      return 0;
    }
  }
  v6 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this: v3);
  if ( v6->GetModelType(this: modelinfo, a2: Model) != 1 )
    return 0;
  return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity: pServerEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x102677B0
// Name: public: class CBaseEntity __near * CDecal::GetDecalEntityAndPosition(class Vector __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CDecal::GetDecalEntityAndPosition(CDecal *this, Vector *pPosition, bool bStatic)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // edi
  int m_iEFlags; // edx
  float z; // ecx
  float v8; // xmm0_4
  float x; // xmm2_4
  float y; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  CGameTrace trace; // [esp+8h] [ebp-88h] BYREF
  CTraceFilterValidForDecal traceFilter; // [esp+5Ch] [ebp-34h] BYREF
  Vector end; // [esp+6Ch] [ebp-24h] BYREF
  Vector direction; // [esp+78h] [ebp-18h] BYREF
  Vector start; // [esp+84h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+90h] [ebp+0h] BYREF

  pszValue = this->m_entityName.pszValue;
  EntityByName = nullptr;
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
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    z = this->m_vecAbsOrigin.z;
    *(_QWORD *)&start.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    v8 = 1.0;
    x = 1.0;
    y = 1.0;
    start.z = z;
    direction.x = 1.0;
    direction.y = 1.0;
    direction.z = 1.0;
    if ( (m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v8 = direction.z;
      y = direction.y;
      x = direction.x;
    }
    if ( vec3_angle.x == this->m_angAbsRotation.x
      && vec3_angle.y == this->m_angAbsRotation.y
      && vec3_angle.z == this->m_angAbsRotation.z )
    {
      v11 = start.x - (float)(x * 5.0);
      v12 = start.y - (float)(y * 5.0);
      v13 = start.z - (float)(v8 * 5.0);
      start.x = v11;
      start.y = v12;
      start.z = v13;
    }
    else
    {
      this->GetVectors(this, a2: &direction, a3: nullptr, a4: nullptr);
      v13 = start.z;
      v12 = start.y;
      v11 = start.x;
      v8 = direction.z;
      y = direction.y;
      x = direction.x;
    }
    end.x = (float)(x * 10.0) + v11;
    end.y = (float)(y * 10.0) + v12;
    end.z = (float)(v8 * 10.0) + v13;
    if ( bStatic )
    {
      CTraceFilterSimple::CTraceFilterSimple(
        this: &traceFilter,
        passedict: this,
        collisionGroup: 0,
        pExtraShouldHitFunc: nullptr);
      traceFilter.__vftable = (CTraceFilterValidForDecal_vtbl *)&CTraceFilterValidForDecal::`vftable';
      UTIL_TraceLine(
        a1: (int)&savedregs,
        a2: (int)this,
        vecAbsStart: &start,
        vecAbsEnd: &end,
        mask: 0x200400Bu,
        pFilter: &traceFilter,
        ptr: &trace);
    }
    else
    {
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &start,
        vecAbsEnd: &end,
        mask: 0x400Bu,
        ignore: this,
        collisionGroup: 0,
        ptr: &trace);
    }
    if ( CGameTrace::DidHitNonWorldEntity(this: &trace) )
    {
      *pPosition = trace.endpos;
      return (CBasePlayer *)trace.m_pEnt;
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  *pPosition = this->m_vecAbsOrigin;
  return EntityByName;
}

//------------------------------------------------------------------------------
// Address: 0x10267A10
// Name: public: void CDecal::TriggerDecal(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecal::TriggerDecal(
        CDecal *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CBasePlayer *DecalEntityAndPosition; // eax
  edict_t *m_pPev; // eax
  signed int v8; // edi
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-2Ch] BYREF
  Vector position; // [esp+44h] [ebp-Ch] BYREF

  DecalEntityAndPosition = CDecal::GetDecalEntityAndPosition(this, pPosition: &position, bStatic: false);
  if ( DecalEntityAndPosition != nullptr )
  {
    m_pPev = DecalEntityAndPosition->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v8 = m_pPev - gpGlobals->pEdicts;
    else
      v8 = 0;
  }
  else
  {
    v8 = 0;
  }
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, Vector *, signed int, int))te->BSPDecal)(
    a1: &filter,
    a2: 0,
    a3: &position,
    a4: v8,
    a5: this->m_nTexture);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10267AD0
// Name: public: void CDecal::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecal::InputActivate(CDecal *this, inputdata_t *inputdata)
{
  CDecal::TriggerDecal(
    this,
    pActivator: inputdata->pActivator,
    pCaller: inputdata->pCaller,
    useType: USE_ON,
    value: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10267B00
// Name: private: void CDecal::StaticDecal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecal::StaticDecal(CDecal *this)
{
  CBasePlayer *DecalEntityAndPosition; // eax
  int v3; // ebx
  CBaseEntity *v4; // esi
  edict_t *m_pPev; // eax
  signed int v6; // eax
  int v7; // eax
  unsigned int v8; // edx
  Vector worldspace; // [esp+Ch] [ebp-1Ch] BYREF
  Vector position; // [esp+18h] [ebp-10h] BYREF
  int modelIndex; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  DecalEntityAndPosition = CDecal::GetDecalEntityAndPosition(this, pPosition: &position, bStatic: true);
  v3 = 0;
  v4 = DecalEntityAndPosition;
  modelIndex = 0;
  if ( DecalEntityAndPosition != nullptr )
  {
    m_pPev = DecalEntityAndPosition->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v6 = m_pPev - gpGlobals->pEdicts;
    else
      v6 = 0;
    v3 = v6;
    v7 = v4->GetModelIndex(this: v4);
    v8 = (unsigned int)v4->m_iEFlags >> 11;
    modelIndex = v7;
    worldspace = position;
    if ( (v8 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
    VectorITransform(in1: &worldspace.x, in2: &v4->m_rgflCoordinateFrame, out: &position.x);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    position = this->m_vecAbsOrigin;
  }
  engine->StaticDecal(
    this: engine,
    a2: &position,
    a3: this->m_nTexture,
    a4: v3,
    a5: modelIndex,
    a6: this->m_bLowPriority);
  CBaseEntity::SUB_Remove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10267C00
// Name: public: virtual void CProjectedDecal::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProjectedDecal::Activate(CProjectedDecal *this)
{
  CRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CBaseEntity::Activate(this);
  if ( this->m_iName.m_Value.pszValue != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::OnSetSchedule,
      thinkTime: 0.0,
      szContext: nullptr);
    this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CProjectedDecal::TriggerDecal;
  }
  else
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
    CRecipientFilter::AddAllPlayers(this: &filter);
    CRecipientFilter::MakeInitMessage(this: &filter);
    CProjectedDecal::ProjectDecal(this, &filter);
    CBaseEntity::SUB_Remove(this);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10267C80
// Name: public: void CProjectedDecal::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProjectedDecal::InputActivate(CProjectedDecal *this, inputdata_t *inputdata)
{
  CRecipientFilter filter; // [esp+Ch] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  CProjectedDecal::ProjectDecal(this, &filter);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10267FA0
// Name: public: virtual void CInfoGameEventProxy::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoGameEventProxy::Spawn(CInfoGameEventProxy *this)
{
  CPointEntity::Spawn(this);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    VisibilityMonitor_AddEntity(
      pEntity: this,
      flMinDist: this->m_flRange,
      pfnCallback: (bool (__cdecl *)(CBaseEntity *, CBasePlayer *))CInfoGameEventProxy::GameEventProxyCallback,
      pfnEvaluator: (bool (__cdecl *)(CBaseEntity *, CBasePlayer *))CInfoGameEventProxy::GameEventProxyEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10267FE0
// Name: public: virtual void CDecal::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecal::Activate(CDecal *this)
{
  CBaseEntity::Activate(this);
  if ( this->m_iName.m_Value.pszValue != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_BaseNPC::OnSetSchedule,
      thinkTime: 0.0,
      szContext: nullptr);
    this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CDecal::TriggerDecal;
  }
  else
  {
    CDecal::StaticDecal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10268020
// Name: public: void CWorld::SetTimeOfDay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::SetTimeOfDay(CWorld *this, int iTimeOfDay)
{
  CNetworkVarBase<int,CWorld::NetworkVar_m_iTimeOfDay> *p_m_iTimeOfDay; // esi
  edict_t *m_pPev; // ecx

  p_m_iTimeOfDay = &this->m_iTimeOfDay;
  if ( this->m_iTimeOfDay.m_Value != iTimeOfDay )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_iTimeOfDay->m_Value = iTimeOfDay;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x38Cu);
      p_m_iTimeOfDay->m_Value = iTimeOfDay;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10268130
// Name: public: virtual bool CWorld::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorld::KeyValue(CWorld *this, char *szKeyName, char *szValue)
{
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  int v7; // eax
  float v8; // [esp+8h] [ebp-Ch] BYREF
  ConVarRef skyname; // [esp+Ch] [ebp-8h] BYREF

  if ( szKeyName == "skyname" || _V_stricmp(s1: szKeyName, s2: "skyname") == 0 )
  {
    ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
    skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: szValue);
    return true;
  }
  if ( szKeyName == "newunit" || _V_stricmp(s1: szKeyName, s2: "newunit") == 0 )
  {
    if ( atoi(nptr: szValue) != 0 )
    {
      Game_SetOneWayTransition();
      return true;
    }
    return true;
  }
  if ( szKeyName == "world_mins" || _V_stricmp(s1: szKeyName, s2: "world_mins") == 0 )
  {
    sscanf(string: szValue, format: "%f %f %f", &v8, &skyname, &skyname.m_pConVarState);
    if ( v8 != this->m_WorldMins.m_Value.x
      || *(float *)&skyname.m_pConVar != this->m_WorldMins.m_Value.y
      || *(float *)&skyname.m_pConVarState != this->m_WorldMins.m_Value.z )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
      }
      this->m_WorldMins.m_Value.x = v8;
      *(ConVarRef *)&this->m_WorldMins.m_Value.y = skyname;
      return true;
    }
    return true;
  }
  if ( szKeyName != "world_maxs" && _V_stricmp(s1: szKeyName, s2: "world_maxs") != 0 )
  {
    if ( szKeyName != "timeofday" && _V_stricmp(s1: szKeyName, s2: "timeofday") != 0 )
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    v7 = atoi(nptr: szValue);
    CWorld::SetTimeOfDay(this, iTimeOfDay: v7);
    return true;
  }
  sscanf(string: szValue, format: "%f %f %f", &v8, &skyname, &skyname.m_pConVarState);
  if ( v8 == this->m_WorldMaxs.m_Value.x
    && *(float *)&skyname.m_pConVar == this->m_WorldMaxs.m_Value.y
    && *(float *)&skyname.m_pConVarState == this->m_WorldMaxs.m_Value.z )
  {
    return true;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v6 = this->m_Network.m_pPev;
    if ( v6 != nullptr )
      CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x368u);
  }
  this->m_WorldMaxs.m_Value.x = v8;
  *(ConVarRef *)&this->m_WorldMaxs.m_Value.y = skyname;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x102683A0
// Name: public: CWorld::CWorld(void)
// Source: json
//------------------------------------------------------------------------------
CWorld *__thiscall CWorld::CWorld(CWorld *this)
{
  edict_t *v2; // eax
  edict_t *m_pPev; // ecx
  CWorld *result; // eax
  edict_t *v5; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->m_iEFlags |= 0x410u;
  this->__vftable = (CWorld_vtbl *)&CWorld::`vftable';
  if ( gpGlobals->pEdicts != nullptr )
    v2 = (gpGlobals->pEdicts->m_fStateFlags & 2) == 0 ? gpGlobals->pEdicts : nullptr;
  else
    v2 = nullptr;
  CServerNetworkProperty::AttachEdict(this: &this->m_Network, pRequiredEdict: v2);
  ActivityList_Init();
  EventList_Init();
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BSP);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_bColdWorld.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x389u);
    }
    this->m_bColdWorld.m_Value = false;
  }
  result = this;
  if ( this->m_iTimeOfDay.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iTimeOfDay.m_Value = 0;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x38Cu);
      this->m_iTimeOfDay.m_Value = 0;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10268490
// Name: public: virtual void CWorld::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorld::Precache(CWorld *this)
{
  unsigned int v2; // edi
  const char *v3; // eax
  vgui::Panel *v4; // ecx
  vgui::Panel *v5; // ecx
  const char *v6; // eax
  CMessage *v7; // eax
  int v8; // edi
  bool v9; // zf
  CBaseEdict *v10; // edx
  const char *v11; // ebx
  unsigned int v12; // [esp+20h] [ebp-24h]
  CGameTrace *v13; // [esp+24h] [ebp-20h]
  ConVarRef roomtype; // [esp+2Ch] [ebp-18h] BYREF
  ConVarRef stepsize; // [esp+34h] [ebp-10h] BYREF
  char pszValue[4]; // [esp+3Ch] [ebp-8h] BYREF
  CMessage *pMessage; // [esp+40h] [ebp-4h]

  _COM_TimestampedLog(a1: "CWorld::Precache - Start");
  v2 = 0;
  g_WorldEntity = this;
  g_fGameOver = false;
  g_pLastSpawn = nullptr;
  CCollisionProperty::TestCollision(this: (ConVar *)&g_Language.IConVar, value: 0, fContentsMask: v12, tr: v13);
  ConVarRef::ConVarRef(this: &stepsize, pName: "sv_stepsize");
  stepsize.m_pConVar->SetValue_2(this: stepsize.m_pConVar, a2: 18);
  ConVarRef::ConVarRef(this: &roomtype, pName: "room_type");
  roomtype.m_pConVar->SetValue_2(this: roomtype.m_pConVar, a2: 0);
  if ( g_pGameRules != nullptr )
    ((void (__thiscall *)(CGameRules *, int))g_pGameRules->dtr_IGameSystem)(a1: g_pGameRules, a2: 1);
  InstallGameRules();
  g_pGameRules->Init(this: g_pGameRules);
  CSoundEnt::InitSoundEnt();
  ActivityList_Free();
  ActivityList_RegisterSharedActivities();
  EventList_Free();
  EventList_RegisterSharedEvents();
  CBaseEntity::SetAllowPrecache(allow: true);
  _COM_TimestampedLog(a1: "IGameSystem::LevelInitPreEntityAllSystems");
  v3 = *(const char **)((int (__thiscall *)(CWorld *, char *))this->GetModelName)(a1: this, a2: pszValue);
  if ( v3 == nullptr )
    v3 = locale;
  IGameSystem::LevelInitPreEntityAllSystems(pMapName: v3);
  _COM_TimestampedLog(a1: "g_pGameRules->CreateStandardEntities()");
  g_pGameRules->CreateStandardEntities(this: g_pGameRules);
  _COM_TimestampedLog(a1: "InitBodyQue()");
  CAI_BaseNPC::OnSetSchedule(this: v4);
  _COM_TimestampedLog(a1: "SENTENCEG_Init()");
  SENTENCEG_Init();
  _COM_TimestampedLog(a1: "PrecacheStandardParticleSystems()");
  PrecacheStandardParticleSystems();
  _COM_TimestampedLog(a1: "W_Precache()");
  W_Precache();
  _COM_TimestampedLog(a1: "ClientPrecache()");
  ClientPrecache();
  _COM_TimestampedLog(a1: "PrecacheTempEnts()");
  CBaseTempEntity::PrecacheTempEnts();
  _COM_TimestampedLog(a1: "LightStyles");
  do
  {
    engine->LightStyle(this: engine, a2: v2, a3: g_DefaultLightstyles[v2]);
    ++v2;
  }
  while ( v2 < 0xD );
  engine->LightStyle(this: engine, a2: 63, a3: "a");
  _COM_TimestampedLog(a1: "InitializeAINetworks");
  CAI_NetworkManager::InitializeAINetworks();
  _COM_TimestampedLog(a1: "LoadAllSchedules");
  CAI_SchedulesManager::LoadAllSchedules(this: &g_AI_SchedulesManager);
  _COM_TimestampedLog(a1: "InitDefaultAIRelationships");
  g_pGameRules->InitDefaultAIRelationships(this: g_pGameRules);
  _COM_TimestampedLog(a1: "InitInteractionSystem");
  CAI_BaseNPC::OnSetSchedule(this: v5);
  _COM_TimestampedLog(a1: "g_pGameRules->Precache");
  g_pGameRules->Precache(this: g_pGameRules);
  if ( this->m_iszChapterTitle.pszValue != nullptr )
  {
    v6 = this->m_iszChapterTitle.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    _DevMsg(a1: 2, a2: "Chapter title: %s\n", v6);
    v7 = (CMessage *)CBaseEntity::Create(
                       szName: "env_message",
                       vecOrigin: &vec3_origin,
                       vecAngles: &vec3_angle,
                       pOwner: nullptr);
    pMessage = v7;
    if ( v7 != nullptr )
    {
      v7->m_iszMessage.pszValue = this->m_iszChapterTitle.pszValue;
      this->m_iszChapterTitle.pszValue = nullptr;
      v8 = v7->m_spawnflags.m_Value | 1;
      if ( v7->m_spawnflags.m_Value != v8 )
      {
        v9 = !v7->m_Network.m_TimerEvent.m_bRegistered;
        *(_DWORD *)pszValue = v7;
        if ( v9 )
        {
          v10 = &v7->m_Network.m_pPev->CBaseEdict;
          if ( v10 != nullptr )
          {
            CBaseEdict::StateChanged(this: v10, offset: (_WORD)v7 + 760 - *(_WORD *)pszValue);
            v7 = pMessage;
          }
        }
        else
        {
          *((_BYTE *)&v7->m_Network + 76) |= 1u;
        }
        v7->m_spawnflags.m_Value = v8;
      }
      CBaseEntity::ThinkSet(this: v7, func: CBaseEntity::SUB_CallUseToggle, thinkTime: 0.0, szContext: nullptr);
      CBaseEntity::SetNextThink(this: pMessage, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
    }
  }
  g_iszFuncBrushClassname.pszValue = *(const char **)AllocPooledString(pszValue).pszValue;
  if ( this->m_iszDetailSpriteMaterial.m_Value.pszValue != nullptr )
  {
    v11 = this->m_iszDetailSpriteMaterial.m_Value.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    PrecacheMaterial(pMaterialName: v11);
  }
  _COM_TimestampedLog(a1: "CWorld::Precache - Finish");
}

//------------------------------------------------------------------------------
// Address: 0x1040D0C0
// Name: CInfoGameEventProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoGameEventProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoGameEventProxy>();
  CInfoGameEventProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D0D0
// Name: CDecal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDecal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDecal>();
  CDecal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D100
// Name: CProjectedDecal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CProjectedDecal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CProjectedDecal>();
  CProjectedDecal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D150
// Name: CWorld_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWorld_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWorld>();
  CWorld_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D180
// Name: DT_WORLD::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WORLD::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WORLD::g_SendTable);
  return atexit(func: DT_WORLD::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D1A0
// Name: DT_WORLD::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WORLD::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WORLD::ignored>();
  DT_WORLD::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F300
// Name: DT_WORLD::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WORLD::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WORLD::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040D0E0
// Name: _dynamic_initializer_for__infodecal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__infodecal__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CDecal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &infodecal,
           a3: "infodecal");
}

//------------------------------------------------------------------------------
// Address: 0x1040D160
// Name: _dynamic_initializer_for__g_CWorld_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWorld_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CWorld_ClassReg, pNetworkName: "CWorld", pTable: &DT_WORLD::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041F310
// Name: _ServerClassInit_DT_WORLD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WORLD::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_28;
  for ( i = 11; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041F330
// Name: _DataMapInit_CInfoGameEventProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoGameEventProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_467);
}

//------------------------------------------------------------------------------
// Address: 0x1041F340
// Name: _DataMapInit_CDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_468);
}

//------------------------------------------------------------------------------
// Address: 0x1041F350
// Name: _DataMapInit_CProjectedDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CProjectedDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_469);
}

//------------------------------------------------------------------------------
// Address: 0x1041F360
// Name: _DataMapInit_CWorld__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CWorld__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_470);
}
