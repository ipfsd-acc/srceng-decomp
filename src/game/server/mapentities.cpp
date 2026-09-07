// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/mapentities.cpp
// Functions: 20
// ============================================================

#include "game\server\mapentities.h"

//------------------------------------------------------------------------------
// Address: 0x1016EEC0
// Name: class CBaseEntity __near * CreateEntityByName(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__cdecl CreateEntityByName(const char *className, int iForceEdictIndex, bool bNotify)
{
  IEntityFactoryDictionary *v3; // eax
  IServerNetworkable *result; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // esi

  if ( iForceEdictIndex != -1 )
  {
    g_pForceAttachEdict = engine->CreateEdict(this: engine, a2: iForceEdictIndex);
    if ( g_pForceAttachEdict == nullptr )
      _Error(this: (ISceneTokenProcessor *)&stru_1048F22C, a2: className, iForceEdictIndex);
  }
  v3 = EntityFactoryDictionary();
  result = v3->Create(this: v3, a2: className);
  g_pForceAttachEdict = nullptr;
  if ( result != nullptr )
  {
    v5 = result->GetBaseEntity(this: result);
    v6 = v5;
    if ( bNotify )
      CGlobalEntityList::NotifyCreateEntity(this: &gEntList, pEnt: v5);
    return (IServerNetworkable *)v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016EF40
// Name: struct string_t ExtractParentName(struct string_t)
// Source: json
//------------------------------------------------------------------------------
string_t __cdecl ExtractParentName(char *parentName, string_t parentNamea)
{
  char *pszValue; // eax
  int v3; // eax
  const char *v5; // eax
  char szToken[256]; // [esp+0h] [ebp-100h] BYREF

  pszValue = (char *)parentNamea.pszValue;
  if ( parentNamea.pszValue == nullptr )
    pszValue = (char *)locale;
  strchr(string: pszValue, chr: 0x2Cu);
  if ( v3 != 0 )
  {
    v5 = parentNamea.pszValue;
    if ( parentNamea.pszValue == nullptr )
      v5 = locale;
    nexttoken(token: szToken, str: v5, sep: 44);
    AllocPooledString(pszValue: parentName, pszValuea: szToken);
    return (string_t)parentName;
  }
  else
  {
    *(string_t *)parentName = parentNamea;
    return (string_t)parentName;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016EFB0
// Name: void MapEntity_ParseAllEntites_SpawnTemplates(class CPointTemplate __near * __near *,int,class CBaseEntity __near * __near *,struct HierarchicalSpawnMapData_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapEntity_ParseAllEntites_SpawnTemplates(
        CPointTemplate **pTemplates,
        int iTemplateCount,
        CBaseEntity **pSpawnedEntities,
        HierarchicalSpawnMapData_t *pSpawnMapData,
        int iSpawnedEntityCount)
{
  int v5; // esi
  CPointTemplate *v6; // ebx
  CBaseEntity *TemplateEntity; // edi
  int v8; // esi
  int iNumTemplates; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int iTemplateNum; // [esp+Ch] [ebp-4h]

  v5 = 0;
  for ( i = 0; v5 < iTemplateCount; i = v5 )
  {
    v6 = pTemplates[v5];
    if ( DispatchSpawn(pEntity: v6, bRunVScripts: true) >= 0 )
    {
      CPointTemplate::StartBuildingTemplates(this: v6);
      iNumTemplates = CPointTemplate::GetNumTemplateEntities(this: v6);
      iTemplateNum = 0;
      if ( iNumTemplates > 0 )
      {
        do
        {
          TemplateEntity = CPointTemplate::GetTemplateEntity(this: v6, iTemplateNumber: iTemplateNum);
          v8 = 0;
          if ( iSpawnedEntityCount > 0 )
          {
            while ( pSpawnedEntities[v8] != TemplateEntity )
            {
              if ( ++v8 >= iSpawnedEntityCount )
                goto LABEL_11;
            }
            CPointTemplate::AddTemplate(
              this: v6,
              pEntity: TemplateEntity,
              pszMapData: pSpawnMapData[v8].m_pMapData,
              nLen: pSpawnMapData[v8].m_iMapDataLength);
            if ( CPointTemplate::ShouldRemoveTemplateEntities(this: v6) )
            {
              UTIL_Remove(oldObj: TemplateEntity);
              CGlobalEntityList::CleanupDeleteList(this: &gEntList);
              pSpawnedEntities[v8] = nullptr;
            }
          }
LABEL_11:
          ++iTemplateNum;
        }
        while ( iTemplateNum < iNumTemplates );
        v5 = i;
      }
      CPointTemplate::FinishBuildingTemplates(this: v6);
    }
    else
    {
      UTIL_Remove(oldObj: v6);
      CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    }
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F0A0
// Name: void MapEntity_PrecacheEntity(char const __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapEntity_PrecacheEntity(char *pEntData, int *nStringSize)
{
  int v2; // edx
  IEntityFactoryDictionary *v3; // eax
  int v4; // eax
  CBaseEntity *v5; // esi
  char className[2048]; // [esp+0h] [ebp-80Ch] BYREF
  CEntityMapData entData; // [esp+800h] [ebp-Ch] BYREF

  v2 = *nStringSize;
  entData.m_pEntData = pEntData;
  entData.m_pCurrentKey = pEntData;
  entData.m_nEntDataSize = v2;
  if ( !CEntityMapData::ExtractValue(this: &entData, keyName: "classname", value: className) )
    _Error(this: (ISceneTokenProcessor *)&stru_1048F260, a2: *(const char **)className);
  v3 = EntityFactoryDictionary();
  v4 = (int)v3->Create(this: v3, a2: className);
  g_pForceAttachEdict = nullptr;
  if ( v4 != 0 )
  {
    v5 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 28))(a1: v4);
    CGlobalEntityList::NotifyCreateEntity(this: &gEntList, pEnt: v5);
    if ( v5 != nullptr )
    {
      CBaseEntity::ParseMapData(this: v5, mapData: &entData);
      v5->Precache(this: v5);
      UTIL_RemoveImmediate(oldObj: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F140
// Name: char const __near * MapEntity_ParseEntity(class CBaseEntity __near * __near &,char const __near *,class IMapEntityFilter __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__usercall MapEntity_ParseEntity@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseEntity **pEntity,
        char *pEntData,
        IMapEntityFilter *pFilter)
{
  bool v6; // bl
  IEntityFactoryDictionary *v7; // eax
  int v8; // eax
  CBaseEntity *v9; // esi
  char keyName[2048]; // [esp+0h] [ebp-180Ch] BYREF
  char v13[2048]; // [esp+800h] [ebp-100Ch] BYREF
  char value[2048]; // [esp+1000h] [ebp-80Ch] BYREF
  CEntityMapData mapData; // [esp+1800h] [ebp-Ch] BYREF

  mapData.m_pEntData = pEntData;
  mapData.m_pCurrentKey = pEntData;
  mapData.m_nEntDataSize = -1;
  if ( !CEntityMapData::ExtractValue(this: &mapData, keyName: "classname", value) )
    _Error(this: (ISceneTokenProcessor *)&stru_1048F260, a2: *(const char **)keyName);
  v6 = false;
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
    v6 = V_strnicmp(s1: "weapon_", s2: value, n: 7) == 0;
  *pEntity = nullptr;
  if ( pFilter != nullptr )
  {
    if ( ((int (__thiscall *)(IMapEntityFilter *, char *, int, int, int))pFilter->ShouldCreateEntity)(
           a1: pFilter,
           a2: value,
           a3: a2,
           a4: a3,
           a5: a1) == 0
      || v6 )
    {
      if ( CEntityMapData::GetFirstKey(this: &mapData, keyName, value: v13) )
      {
        while ( CEntityMapData::GetNextKey(this: &mapData, keyName, value: v13) )
          ;
      }
      return (const char *)CBaseTempEntity::GetNext(this: (CBaseAchievement *)&mapData);
    }
    *pEntity = pFilter->CreateNextEntity(this: pFilter, a2: value);
  }
  else
  {
    v7 = EntityFactoryDictionary();
    v8 = ((int (__thiscall *)(IEntityFactoryDictionary *, char *, int, int, int))v7->Create)(
           a1: v7,
           a2: value,
           a3: a2,
           a4: a3,
           a5: a1);
    v9 = nullptr;
    g_pForceAttachEdict = nullptr;
    if ( v8 != 0 )
    {
      v9 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 28))(a1: v8);
      CGlobalEntityList::NotifyCreateEntity(this: &gEntList, pEnt: v9);
    }
    *pEntity = v9;
  }
  if ( *pEntity != nullptr )
  {
    CBaseEntity::ParseMapData(this: *pEntity, &mapData);
    return (const char *)CBaseTempEntity::GetNext(this: (CBaseAchievement *)&mapData);
  }
  _Warning(a1: "Can't init %s\n", value);
  return (const char *)CBaseTempEntity::GetNext(this: (CBaseAchievement *)&mapData);
}

//------------------------------------------------------------------------------
// Address: 0x1016F2C0
// Name: void FreeContainingEntity(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FreeContainingEntity(edict_t *ed)
{
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  if ( ed != nullptr )
  {
    m_pUnk = ed->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v2 = m_pUnk->GetBaseEntity(this: m_pUnk);
      v3 = v2;
      if ( v2 != nullptr )
      {
        ed->m_pUnk = nullptr;
        ed->m_fStateFlags = 0;
        CBaseEntity::PhysicsRemoveTouchedList(ent: v2);
        CBaseEntity::PhysicsRemoveGroundList(ent: v3);
        UTIL_RemoveImmediate(oldObj: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F310
// Name: CompareSpawnOrder
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareSpawnOrder(HierarchicalSpawn_t *pEnt1, HierarchicalSpawn_t *pEnt2)
{
  int m_nDepth; // eax
  int v3; // ecx
  CStringRegistry *v4; // ecx
  const char *pszValue; // eax
  int StringID; // eax
  int v7; // esi
  const char *v8; // eax
  int v9; // eax

  m_nDepth = pEnt1->m_nDepth;
  v3 = pEnt2->m_nDepth;
  if ( m_nDepth != v3 )
    return 2 * (m_nDepth > v3) - 1;
  v4 = g_pClassnameSpawnPriority;
  if ( g_pClassnameSpawnPriority == nullptr )
    return 0;
  if ( pEnt1->m_pEntity != nullptr )
  {
    pszValue = pEnt1->m_pEntity->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    StringID = CStringRegistry::GetStringID(this: g_pClassnameSpawnPriority, stringText: pszValue);
    v4 = g_pClassnameSpawnPriority;
    v7 = StringID;
  }
  else
  {
    v7 = -1;
  }
  if ( pEnt2->m_pEntity != nullptr )
  {
    v8 = pEnt2->m_pEntity->m_iClassname.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    v9 = CStringRegistry::GetStringID(this: v4, stringText: v8);
  }
  else
  {
    v9 = -1;
  }
  if ( v9 > v7 )
    return 1;
  if ( v9 < v7 )
    return -1;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1016F3A0
// Name: ComputeSpawnHierarchyDepth_r
// Source: json
//------------------------------------------------------------------------------
int __cdecl ComputeSpawnHierarchyDepth_r(CBaseEntity *pEntity)
{
  CBaseEntity *v1; // esi
  string_t v2; // eax
  CBasePlayer *EntityByName; // eax
  const char *DebugName; // eax

  v1 = pEntity;
  if ( pEntity == nullptr || pEntity->m_iParent.pszValue == nullptr )
    return 1;
  v2.pszValue = *(const char **)ExtractParentName(parentName: (char *)&pEntity, parentNamea: pEntity->m_iParent).pszValue;
  if ( v2.pszValue == nullptr )
    v2.pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v2.pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return 1;
  if ( EntityByName == v1 )
  {
    DebugName = CBaseEntity::GetDebugName(this: v1);
    _Warning(a1: "LEVEL DESIGN ERROR: Entity %s is parented to itself!\n", DebugName);
    return 1;
  }
  return ComputeSpawnHierarchyDepth_r(pEntity: EntityByName) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016F420
// Name: ComputeSpawnHierarchyDepth
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeSpawnHierarchyDepth(int nEntities@<eax>, HierarchicalSpawn_t *pSpawnList@<ecx>)
{
  int *p_m_nDepth; // edi
  CBaseEntity *v3; // esi
  string_t v4; // eax
  CBasePlayer *EntityByName; // eax
  const char *DebugName; // eax
  string_t parentName; // [esp+0h] [ebp-8h] BYREF
  int i; // [esp+4h] [ebp-4h]

  if ( nEntities > 0 )
  {
    p_m_nDepth = &pSpawnList->m_nDepth;
    for ( i = nEntities; i != 0; --i )
    {
      v3 = (CBaseEntity *)*(p_m_nDepth - 1);
      if ( v3 == nullptr || CBaseEntity::IsDormant(this: (CBaseEntity *)*(p_m_nDepth - 1)) )
      {
        *p_m_nDepth = 1;
      }
      else if ( v3->m_iParent.pszValue != nullptr )
      {
        v4.pszValue = *(const char **)ExtractParentName((char *)&parentName, parentNamea: v3->m_iParent).pszValue;
        if ( v4.pszValue == nullptr )
          v4.pszValue = locale;
        EntityByName = CGlobalEntityList::FindEntityByName(
                         this: &gEntList,
                         pStartEntity: nullptr,
                         szName: v4.pszValue,
                         pSearchingEntity: nullptr,
                         pActivator: nullptr,
                         pCaller: nullptr,
                         pFilter: nullptr);
        if ( EntityByName != nullptr )
        {
          if ( EntityByName == v3 )
          {
            DebugName = CBaseEntity::GetDebugName(this: v3);
            _Warning(a1: "LEVEL DESIGN ERROR: Entity %s is parented to itself!\n", DebugName);
            *p_m_nDepth = 1;
          }
          else
          {
            *p_m_nDepth = ComputeSpawnHierarchyDepth_r(pEntity: EntityByName) + 1;
          }
        }
        else
        {
          *p_m_nDepth = 1;
        }
      }
      else
      {
        *p_m_nDepth = 1;
      }
      p_m_nDepth += 4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F500
// Name: SortSpawnListByHierarchy
// Source: json
//------------------------------------------------------------------------------
void __cdecl SortSpawnListByHierarchy(unsigned int nEntities, HierarchicalSpawn_t *pSpawnList)
{
  CStringRegistry *v2; // eax
  CStringRegistry *v3; // eax
  CStringRegistry *v4; // esi

  v2 = (CStringRegistry *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    v3 = CStringRegistry::CStringRegistry(this: v2);
  else
    v3 = nullptr;
  g_pClassnameSpawnPriority = v3;
  CStringRegistry::AddString(this: v3, stringText: "func_wall", stringID: 10);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "scripted_sequence", stringID: 9);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_hinge", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_ballsocket", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_slideconstraint", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_constraint", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_pulleyconstraint", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_lengthconstraint", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "phys_ragdollconstraint", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "info_mass_center", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "trigger_vphysics_motion", stringID: 8);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "prop_physics", stringID: 7);
  CStringRegistry::AddString(this: g_pClassnameSpawnPriority, stringText: "prop_ragdoll", stringID: 7);
  qsort(
    base: (char *)pSpawnList,
    num: nEntities,
    width: 0x10u,
    comp: (int (__cdecl *)(const void *, const void *))CompareSpawnOrder);
  v4 = g_pClassnameSpawnPriority;
  if ( g_pClassnameSpawnPriority != nullptr )
  {
    CStringRegistry::~CStringRegistry(this: g_pClassnameSpawnPriority);
    free(pMem: v4);
  }
  g_pClassnameSpawnPriority = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1016F650
// Name: void SpawnAllEntities(int,struct HierarchicalSpawn_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpawnAllEntities(int nEntities, HierarchicalSpawn_t *pSpawnList, bool bActivateEntities)
{
  int v3; // esi
  CBaseEntity **p_m_pDeferredParent; // edi
  CBaseEntity *v5; // eax
  IMDLCache *v6; // esi
  CBaseEntity *v7; // edi
  int v8; // ebx
  CBaseAnimating *v9; // eax
  HierarchicalSpawn_t *v10; // eax
  int v11; // edx
  bool v12; // zf
  HierarchicalSpawn_t *v13; // ebx
  CBaseEntity *m_pEntity; // edi
  IMDLCache *v15; // esi
  int v16; // [esp+Ch] [ebp-Ch]
  CBaseEntity *pEntity; // [esp+10h] [ebp-8h]
  CBaseEntity **v18; // [esp+14h] [ebp-4h]
  int bActivateEntitiesa; // [esp+28h] [ebp+10h]

  v3 = nEntities;
  if ( nEntities > 0 )
  {
    p_m_pDeferredParent = &pSpawnList->m_pDeferredParent;
    v18 = &pSpawnList->m_pDeferredParent;
    v16 = nEntities;
    do
    {
      v5 = *(p_m_pDeferredParent - 2);
      pEntity = v5;
      if ( *p_m_pDeferredParent != nullptr )
      {
        v6 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        v7 = *p_m_pDeferredParent;
        v8 = -1;
        v9 = v7->GetBaseAnimating(this: v7);
        if ( v9 != nullptr )
          v8 = CBaseAnimating::LookupAttachment(this: v9, szName: (const char *)v18[1]);
        pEntity->SetParent(this: pEntity, a2: v7, a3: v8);
        v6->EndLock(this: v6);
        v3 = nEntities;
        v5 = pEntity;
        p_m_pDeferredParent = v18;
      }
      if ( v5 != nullptr && DispatchSpawn(pEntity: v5, bRunVScripts: true) < 0 )
      {
        v10 = pSpawnList;
        v11 = v3;
        do
        {
          if ( v10->m_pEntity != nullptr && (v10->m_pEntity->m_iEFlags & 1) != 0 )
            v10->m_pEntity = nullptr;
          ++v10;
          --v11;
        }
        while ( v11 != 0 );
        CGlobalEntityList::CleanupDeleteList(this: &gEntList);
        *(p_m_pDeferredParent - 2) = nullptr;
      }
      p_m_pDeferredParent += 4;
      v12 = v16-- == 1;
      v18 = p_m_pDeferredParent;
    }
    while ( !v12 );
  }
  if ( bActivateEntities )
  {
    LOBYTE(nEntities) = mdlcache->SetAsyncLoad(this: mdlcache, a2: MDLCACHE_ANIMBLOCK, a3: false);
    if ( v3 > 0 )
    {
      v13 = pSpawnList;
      for ( bActivateEntitiesa = v3; bActivateEntitiesa != 0; --bActivateEntitiesa )
      {
        m_pEntity = v13->m_pEntity;
        if ( v13->m_pEntity != nullptr )
        {
          v15 = mdlcache;
          mdlcache->BeginLock(this: mdlcache);
          m_pEntity->Activate(this: m_pEntity);
          v15->EndLock(this: v15);
        }
        ++v13;
      }
    }
    mdlcache->SetAsyncLoad(this: mdlcache, a2: MDLCACHE_ANIMBLOCK, a3: nEntities);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F7A0
// Name: public: void CMapEntitySpawner::PurgeRemovedEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntitySpawner::PurgeRemovedEntities(CMapEntitySpawner *this)
{
  int v1; // edi
  int v2; // esi
  HierarchicalSpawn_t *m_pSpawnList; // edx
  CBaseEntity *m_pEntity; // eax

  v1 = 0;
  if ( this->m_nEntities > 0 )
  {
    v2 = 0;
    do
    {
      m_pSpawnList = this->m_pSpawnList;
      m_pEntity = m_pSpawnList[v2].m_pEntity;
      if ( m_pEntity != nullptr && (m_pEntity->m_iEFlags & 1) != 0 )
        m_pSpawnList[v2].m_pEntity = nullptr;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_nEntities );
  }
  CGlobalEntityList::CleanupDeleteList(this: &gEntList);
}

//------------------------------------------------------------------------------
// Address: 0x1016F7E0
// Name: void SetupParentsForSpawnList(int,struct HierarchicalSpawn_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupParentsForSpawnList(int nEntities, HierarchicalSpawn_t *pSpawnList)
{
  int v2; // edi
  const char **p_m_pDeferredParentAttachment; // ebx
  _DWORD *v4; // esi
  char *v5; // eax
  int v6; // eax
  bool v7; // zf
  const char *v8; // eax
  const char *v9; // edi
  string_t v10; // eax
  CBasePlayer *v11; // eax
  CBasePlayer *EntityByName; // eax
  char szToken[256]; // [esp+4h] [ebp-104h] BYREF
  char pszValue[4]; // [esp+104h] [ebp-4h] BYREF
  int nEntity; // [esp+110h] [ebp+8h]

  v2 = nEntities - 1;
  nEntity = nEntities - 1;
  if ( nEntity >= 0 )
  {
    p_m_pDeferredParentAttachment = &pSpawnList[v2].m_pDeferredParentAttachment;
    do
    {
      v4 = *(p_m_pDeferredParentAttachment - 3);
      if ( v4 != nullptr )
      {
        v5 = (char *)v4[128];
        if ( v5 == nullptr )
          v5 = (char *)locale;
        strchr(string: v5, chr: 0x2Cu);
        v7 = v6 == 0;
        v8 = (const char *)v4[128];
        if ( v7 )
        {
          if ( v8 == nullptr )
            v8 = locale;
          EntityByName = CGlobalEntityList::FindEntityByName(
                           this: &gEntList,
                           pStartEntity: nullptr,
                           szName: v8,
                           pSearchingEntity: nullptr,
                           pActivator: nullptr,
                           pCaller: nullptr,
                           pFilter: nullptr);
          if ( EntityByName != nullptr && EntityByName->m_Network.m_pPev != nullptr )
            (*(void (__thiscall **)(_DWORD *, CBasePlayer *, int))(*v4 + 148))(a1: v4, a2: EntityByName, a3: -1);
        }
        else
        {
          if ( v8 == nullptr )
            v8 = locale;
          v9 = nexttoken(token: szToken, str: v8, sep: 44);
          v10.pszValue = *(const char **)AllocPooledString(pszValue, pszValuea: szToken).pszValue;
          v4[128] = v10.pszValue;
          if ( v10.pszValue == nullptr )
            v10.pszValue = locale;
          v11 = CGlobalEntityList::FindEntityByName(
                  this: &gEntList,
                  pStartEntity: nullptr,
                  szName: v10.pszValue,
                  pSearchingEntity: nullptr,
                  pActivator: nullptr,
                  pCaller: nullptr,
                  pFilter: nullptr);
          *p_m_pDeferredParentAttachment = v9;
          v2 = nEntity;
          *(p_m_pDeferredParentAttachment - 1) = (const char *)v11;
        }
      }
      --v2;
      p_m_pDeferredParentAttachment -= 4;
      nEntity = v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F8E0
// Name: public: void CMapEntitySpawner::HandleTemplates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntitySpawner::HandleTemplates(CMapEntitySpawner *this)
{
  int m_nEntities; // edi
  void *v3; // esp
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // edx
  HierarchicalSpawn_t *v8; // ecx
  int v9; // eax
  int v10; // ecx
  CBaseEntity *v11[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_PointTemplates.m_Size != 0 )
  {
    m_nEntities = this->m_nEntities;
    v3 = alloca(4 * m_nEntities);
    v4 = 0;
    if ( m_nEntities != 0 )
    {
      v5 = 0;
      do
        v11[v4++] = this->m_pSpawnList[v5++].m_pEntity;
      while ( v4 != this->m_nEntities );
    }
    v6 = 0;
    if ( this->m_nEntities > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->m_pSpawnList[v7];
        if ( v8->m_pEntity != nullptr && (v8->m_pEntity->m_iEFlags & 1) != 0 )
          v8->m_pEntity = nullptr;
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_nEntities );
    }
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    MapEntity_ParseAllEntites_SpawnTemplates(
      pTemplates: this->m_PointTemplates.m_Memory.m_pMemory,
      iTemplateCount: this->m_PointTemplates.m_Size,
      pSpawnedEntities: v11,
      pSpawnMapData: this->m_pSpawnMapData,
      iSpawnedEntityCount: this->m_nEntities);
    v9 = 0;
    if ( this->m_nEntities != 0 )
    {
      v10 = 0;
      do
        this->m_pSpawnList[v10++].m_pEntity = v11[v9++];
      while ( v9 != this->m_nEntities );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F9A0
// Name: void SpawnHierarchicalList(int,struct HierarchicalSpawn_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpawnHierarchicalList(int nEntities, HierarchicalSpawn_t *pSpawnList, bool bActivateEntities)
{
  HierarchicalSpawn_t *v3; // esi
  int i; // edi

  v3 = pSpawnList;
  ComputeSpawnHierarchyDepth(nEntities, pSpawnList);
  SortSpawnListByHierarchy(nEntities, pSpawnList);
  if ( engine->IsInEditMode(this: engine) != 0 && nEntities > 0 )
  {
    for ( i = nEntities; i != 0; --i )
    {
      if ( v3->m_pEntity != nullptr )
        NWCEdit::RememberEntityPosition(pEntity: v3->m_pEntity);
      ++v3;
    }
    v3 = pSpawnList;
  }
  SetupParentsForSpawnList(nEntities, pSpawnList: v3);
  SpawnAllEntities(nEntities, pSpawnList: v3, bActivateEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1016FA10
// Name: public: void CMapEntitySpawner::SpawnAndActivate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntitySpawner::SpawnAndActivate(CMapEntitySpawner *this, bool bActivateEntities)
{
  SpawnHierarchicalList(nEntities: this->m_nEntities, pSpawnList: this->m_pSpawnList, bActivateEntities);
}

//------------------------------------------------------------------------------
// Address: 0x1016FA30
// Name: public: CMapEntitySpawner::CMapEntitySpawner(void)
// Source: json
//------------------------------------------------------------------------------
CMapEntitySpawner *__thiscall CMapEntitySpawner::CMapEntitySpawner(CMapEntitySpawner *this)
{
  this->m_PointTemplates.m_Memory.m_pMemory = nullptr;
  this->m_PointTemplates.m_Memory.m_nAllocationCount = 0;
  this->m_PointTemplates.m_Memory.m_nGrowSize = 0;
  this->m_PointTemplates.m_Size = 0;
  this->m_PointTemplates.m_pElements = nullptr;
  this->m_nEntities = 0;
  this->m_pSpawnMapData = (HierarchicalSpawnMapData_t *)operator new(nSize: 0x10000u);
  this->m_pSpawnList = (HierarchicalSpawn_t *)operator new(nSize: 0x20000u);
  this->m_bFoundryMode = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016FA70
// Name: public: CMapEntitySpawner::~CMapEntitySpawner(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntitySpawner::~CMapEntitySpawner(CMapEntitySpawner *this)
{
  free(pMem: this->m_pSpawnMapData);
  free(pMem: this->m_pSpawnList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PointTemplates);
}

//------------------------------------------------------------------------------
// Address: 0x1016FAA0
// Name: public: void CMapEntitySpawner::AddEntity(class CBaseEntity __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapEntitySpawner::AddEntity(
        CMapEntitySpawner *this,
        CPointTemplate *pEntity,
        char *pCurMapData,
        int iMapDataLength)
{
  CNodeEnt *v6; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPointTemplate **m_pMemory; // ecx
  int v10; // eax
  CPointTemplate **v11; // eax
  CPointTemplate *pTemplate; // [esp+10h] [ebp+8h]

  if ( pEntity->IsTemplate(this: pEntity) )
  {
    if ( this->m_bFoundryMode )
      Templates_RemoveByHammerID(nHammerID: pEntity->m_iHammerID);
    Templates_Add(pEntity, pszMapData: pCurMapData, nLen: iMapDataLength, nHammerID: pEntity->m_iHammerID);
    UTIL_Remove(oldObj: pEntity);
    CMapEntitySpawner::PurgeRemovedEntities(this);
    return;
  }
  if ( __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CWorld `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    pEntity->m_iParent.pszValue = nullptr;
    DispatchSpawn(pEntity, bRunVScripts: true);
    return;
  }
  v6 = (CNodeEnt *)__RTDynamicCast(
                     inptr: pEntity,
                     VfDelta: 0,
                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                     TargetType: &CNodeEnt `RTTI Type Descriptor',
                     isReference: 0);
  if ( v6 != nullptr )
  {
    if ( CNodeEnt::Spawn(this: v6, pMapData: pCurMapData) >= 0 )
      return;
    goto LABEL_9;
  }
  if ( __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CLight `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    if ( DispatchSpawn(pEntity, bRunVScripts: true) >= 0 )
      return;
LABEL_9:
    CMapEntitySpawner::PurgeRemovedEntities(this);
    return;
  }
  pTemplate = (CPointTemplate *)__RTDynamicCast(
                                  inptr: pEntity,
                                  VfDelta: 0,
                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                  TargetType: &CPointTemplate `RTTI Type Descriptor',
                                  isReference: 0);
  if ( pTemplate != nullptr )
  {
    m_Size = this->m_PointTemplates.m_Size;
    m_nAllocationCount = this->m_PointTemplates.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PointTemplates,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_PointTemplates.m_Size;
    m_pMemory = this->m_PointTemplates.m_Memory.m_pMemory;
    v10 = this->m_PointTemplates.m_Size - m_Size - 1;
    this->m_PointTemplates.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
    v11 = &this->m_PointTemplates.m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = pTemplate;
  }
  else
  {
    this->m_pSpawnList[this->m_nEntities].m_pEntity = pEntity;
    this->m_pSpawnList[this->m_nEntities].m_nDepth = 0;
    this->m_pSpawnList[this->m_nEntities].m_pDeferredParentAttachment = nullptr;
    this->m_pSpawnList[this->m_nEntities].m_pDeferredParent = nullptr;
    this->m_pSpawnMapData[this->m_nEntities].m_pMapData = pCurMapData;
    this->m_pSpawnMapData[this->m_nEntities++].m_iMapDataLength = iMapDataLength;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FC70
// Name: void MapEntity_ParseAllEntities(char const __near *,class IMapEntityFilter __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MapEntity_ParseAllEntities(CBaseEntity *pMapData, IMapEntityFilter *pFilter, bool bActivateEntities)
{
  CPointTemplate **m_pMemory; // ebx
  HierarchicalSpawn_t *m_pSpawnList; // edi
  const char *v5; // eax
  char *v6; // esi
  IMapEntityFilter *v7; // ebx
  char *v8; // edi
  const char *Entity; // eax
  char pWorkBuffer[2048]; // [esp+8h] [ebp-1024h] BYREF
  char newToken[2048]; // [esp+808h] [ebp-824h] BYREF
  CMapEntitySpawner v12; // [esp+1008h] [ebp-24h] BYREF

  m_pMemory = nullptr;
  memset(&v12.m_PointTemplates, 0, 24);
  v12.m_pSpawnMapData = (HierarchicalSpawnMapData_t *)operator new(nSize: 0x10000u);
  m_pSpawnList = (HierarchicalSpawn_t *)operator new(nSize: 0x20000u);
  v12.m_pSpawnList = m_pSpawnList;
  v12.m_bFoundryMode = false;
  if ( serverenginetools != nullptr )
    v5 = serverenginetools->GetEntityData(this: serverenginetools, a2: pMapData);
  else
    v5 = (const char *)pMapData;
  v6 = (char *)MapEntity_ParseToken(data: v5, newToken);
  if ( v6 != nullptr )
  {
    v7 = pFilter;
    do
    {
      if ( newToken[0] == 123 )
      {
        v8 = v6;
        v6 = (char *)MapEntity_ParseEntity(
                       a1: (int)v7,
                       a2: (int)v6,
                       a3: (int)v6,
                       pEntity: &pMapData,
                       pEntData: v6,
                       pFilter: v7);
        if ( pMapData != nullptr )
          CMapEntitySpawner::AddEntity(
            this: &v12,
            pEntity: (CPointTemplate *)pMapData,
            pCurMapData: v8,
            iMapDataLength: v6 - v8 + 2);
      }
      else
      {
        _Error(this: (ISceneTokenProcessor *)&stru_1048F388, a2: newToken);
      }
      Entity = MapEntity_SkipToNextEntity(pMapData: v6, pWorkBuffer);
      v6 = (char *)MapEntity_ParseToken(data: Entity, newToken);
    }
    while ( v6 != nullptr );
    m_pMemory = v12.m_PointTemplates.m_Memory.m_pMemory;
    m_pSpawnList = v12.m_pSpawnList;
  }
  CMapEntitySpawner::HandleTemplates(this: &v12);
  SpawnHierarchicalList(nEntities: v12.m_nEntities, pSpawnList: m_pSpawnList, bActivateEntities);
  free(pMem: v12.m_pSpawnMapData);
  free(pMem: m_pSpawnList);
  if ( v12.m_PointTemplates.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}
