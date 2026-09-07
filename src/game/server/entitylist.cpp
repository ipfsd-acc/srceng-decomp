// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entitylist.cpp
// Functions: 77
// ============================================================

#include "game\server\entitylist.h"

//------------------------------------------------------------------------------
// Address: 0x1010D4A0
// Name: public: CBaseEntityClassList::CBaseEntityClassList(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntityClassList *__thiscall CBaseEntityClassList::CBaseEntityClassList(CBaseEntityClassList *this)
{
  CBaseEntityClassList *result; // eax
  CBaseEntityClassList *v2; // ecx

  result = this;
  v2 = s_pClassLists;
  result->__vftable = (CBaseEntityClassList_vtbl *)&CBaseEntityClassList::`vftable';
  result->m_pNextClassList = v2;
  s_pClassLists = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D4C0
// Name: public: CBaseEntityClassList::~CBaseEntityClassList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntityClassList::~CBaseEntityClassList(CBaseEntityClassList *this)
{
  this->__vftable = (CBaseEntityClassList_vtbl *)&CBaseEntityClassList::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1010D4D0
// Name: public: int CGlobalEntityList::NumberOfEntities(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGlobalEntityList::NumberOfEntities(CGlobalEntityList *this)
{
  return this->m_iNumEnts;
}

//------------------------------------------------------------------------------
// Address: 0x1010D4E0
// Name: void RespawnEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RespawnEntities()
{
  g_EntityListSystem.m_bRespawnAllEntities = true;
}

//------------------------------------------------------------------------------
// Address: 0x1010D4F0
// Name: public: class CEntInfo const __near * CBaseEntityList::GetEntInfoPtr(class CBaseHandle const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CEntInfo *__thiscall CBaseEntityList::GetEntInfoPtr(CBaseEntityList *this, const CBaseHandle *hEnt)
{
  if ( hEnt->m_Index == -1 )
    return &this->m_EntPtrArray[0x1FFF];
  else
    return &this->m_EntPtrArray[(unsigned __int16)hEnt->m_Index];
}

//------------------------------------------------------------------------------
// Address: 0x1010D520
// Name: int AimTarget_ListCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AimTarget_ListCount()
{
  return g_AimManager.m_targetList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1010D530
// Name: int SimThink_ListCount(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SimThink_ListCount()
{
  return g_SimThinkManager.m_simThinkList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1010D540
// Name: public: class CBaseEntity __near * CGlobalEntityList::NextEnt(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::NextEnt(CGlobalEntityList *this, CBaseEntity *pCurrentEnt)
{
  CEntInfo *m_pHead; // eax
  unsigned int m_Index; // eax
  CEntInfo *v6; // eax
  CEntInfo *m_pNext; // eax

  if ( pCurrentEnt != nullptr )
  {
    m_Index = pCurrentEnt->GetRefEHandle(this: pCurrentEnt)->m_Index;
    if ( m_Index == -1 )
      m_Index = 0x1FFF;
    else
      m_Index = (unsigned __int16)m_Index;
    v6 = &this->m_EntPtrArray[m_Index];
    if ( v6 != nullptr )
    {
      m_pNext = v6->m_pNext;
      if ( m_pNext != nullptr )
        return (CBaseEntity *)m_pNext->m_pEntity;
    }
  }
  else
  {
    m_pHead = this->m_activeList.m_pHead;
    if ( m_pHead != nullptr )
      return (CBaseEntity *)m_pHead->m_pEntity;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010D5A0
// Name: public: bool CGlobalEntityList::IsEntityPtr(void __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGlobalEntityList::IsEntityPtr(CGlobalEntityList *this, IHandleEntity *pTest)
{
  CEntInfo *m_pHead; // eax

  if ( pTest == nullptr )
    return 0;
  m_pHead = this->m_activeList.m_pHead;
  if ( m_pHead == nullptr )
    return 0;
  while ( pTest != m_pHead->m_pEntity )
  {
    m_pHead = m_pHead->m_pNext;
    if ( m_pHead == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010D5D0
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByClassname(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByClassname(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName)
{
  unsigned int m_Index; // eax
  CEntInfo *m_pNext; // esi
  IHandleEntity *m_pEntity; // ebx
  const char *pszValue; // eax

  if ( pStartEntity != nullptr )
  {
    m_Index = pStartEntity->GetRefEHandle(this: pStartEntity)->m_Index;
    if ( m_Index == -1 )
      m_pNext = this->m_EntPtrArray[0x1FFF].m_pNext;
    else
      m_pNext = this->m_EntPtrArray[(unsigned __int16)m_Index].m_pNext;
  }
  else
  {
    m_pNext = this->m_activeList.m_pHead;
  }
  for ( ; m_pNext != nullptr; m_pNext = m_pNext->m_pNext )
  {
    m_pEntity = m_pNext->m_pEntity;
    if ( m_pNext->m_pEntity != nullptr )
    {
      pszValue = m_pNext->m_iClassName.pszValue;
      if ( pszValue != nullptr )
      {
        if ( pszValue == szName
          || EntityNamesMatchCStrings(pszQuery: szName, pszNameToMatch: m_pNext->m_iClassName.pszValue) != 0 )
        {
          return (CBaseEntity *)m_pEntity;
        }
      }
      else if ( *szName == 0 || *szName == 42 )
      {
        return (CBaseEntity *)m_pEntity;
      }
    }
    else
    {
      DevWarning(a1: "NULL entity in global entity list!\n");
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1010D670
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByTarget(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByTarget(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName)
{
  unsigned int m_Index; // eax
  CEntInfo *m_pNext; // edi
  IHandleEntity *m_pEntity; // esi
  const char *v7; // eax

  if ( pStartEntity != nullptr )
  {
    m_Index = pStartEntity->GetRefEHandle(this: pStartEntity)->m_Index;
    if ( m_Index == -1 )
      m_pNext = this->m_EntPtrArray[0x1FFF].m_pNext;
    else
      m_pNext = this->m_EntPtrArray[(unsigned __int16)m_Index].m_pNext;
  }
  else
  {
    m_pNext = this->m_activeList.m_pHead;
  }
  if ( m_pNext == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pEntity = m_pNext->m_pEntity;
    if ( m_pNext->m_pEntity != nullptr )
      break;
    DevWarning(a1: "NULL entity in global entity list!\n");
LABEL_12:
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return nullptr;
  }
  v7 = (const char *)m_pEntity[44].__vftable;
  if ( v7 == nullptr || v7 != szName && _V_stricmp(s1: v7, s2: szName) != 0 )
    goto LABEL_12;
  return (CBaseEntity *)m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010D710
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityClassNearestFacing(class Vector const __near &,class Vector const __near &,float,char __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityClassNearestFacing(
        CGlobalEntityList *this,
        const Vector *origin,
        const Vector *facing,
        float threshold,
        char *classname)
{
  CEntInfo *m_pHead; // edi
  CBaseEntity *result; // eax
  CBaseEntity *m_pEntity; // esi
  Vector to_ent; // [esp+0h] [ebp-10h] BYREF
  CBaseEntity *best_ent; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  float dot; // [esp+1Ch] [ebp+Ch]

  m_pHead = this->m_activeList.m_pHead;
  result = nullptr;
  best_ent = nullptr;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pEntity = (CBaseEntity *)m_pHead->m_pEntity;
      if ( m_pHead->m_pEntity != nullptr )
      {
        if ( m_pEntity->m_Collision.m_flRadius != 0.0 )
        {
          if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)m_pHead->m_pEntity, a2: (int)&savedregs);
          to_ent.x = m_pEntity->m_vecAbsOrigin.x - origin->x;
          to_ent.y = m_pEntity->m_vecAbsOrigin.y - origin->y;
          to_ent.z = m_pEntity->m_vecAbsOrigin.z - origin->z;
          VectorNormalize(vec: &to_ent);
          dot = (float)((float)(facing->y * to_ent.y) + (float)(facing->x * to_ent.x)) + (float)(facing->z * to_ent.z);
          if ( dot > threshold
            && (m_pEntity->m_iClassname.pszValue == classname
             || CBaseEntity::ClassMatchesComplex(this: m_pEntity, pszClassOrWildcard: classname) != 0)
            && m_pEntity->m_iClassname.pszValue != "worldspawn"
            && CBaseEntity::ClassMatchesComplex(this: m_pEntity, pszClassOrWildcard: "worldspawn") == 0
            && m_pEntity->m_iClassname.pszValue != "soundent"
            && CBaseEntity::ClassMatchesComplex(this: m_pEntity, pszClassOrWildcard: "soundent") == 0 )
          {
            threshold = dot;
            best_ent = m_pEntity;
          }
        }
      }
      else
      {
        DevWarning(a1: "NULL entity in global entity list!\n");
      }
      m_pHead = m_pHead->m_pNext;
    }
    while ( m_pHead != nullptr );
    return best_ent;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010D870
// Name: public: virtual void CNotifyList::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::OnEntityDeleted(CNotifyList *this, CBaseEntity *pEntity)
{
  void (__thiscall *v2)(char *, CBaseEntity *, int, char **); // edx
  CBaseEntity *v3; // edi
  char *v4; // esi
  char *v5; // [esp+8h] [ebp-4h] BYREF

  v2 = *(void (__thiscall **)(char *, CBaseEntity *, int, char **))(*((_DWORD *)this - 1) + 12);
  v3 = pEntity;
  v5 = (char *)&pEntity + 3;
  v4 = (char *)this - 4;
  v2(a1: (char *)this - 4, a2: pEntity, a3: 1, a4: &v5);
  (*(void (__thiscall **)(char *, CBaseEntity *))(*(_DWORD *)v4 + 16))(a1: v4, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1010D8B0
// Name: public: int CUtlSortVector<class CBaseEntity __near *,class CSortedEntityList::CEntityReportLess>::FindLessOrEqual(class CBaseEntity __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::FindLessOrEqual(
        CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess> *this,
        CBaseEntity *const *src)
{
  int v3; // ebx
  const char *pszValue; // eax
  int v5; // esi
  const char *v6; // ecx
  const char *v7; // ecx
  const char *v8; // eax
  int start; // [esp+10h] [ebp-4h]

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 277);
  }
  v3 = this->m_Size - 1;
  start = 0;
  if ( v3 < 0 )
    return v3;
  while ( 1 )
  {
    pszValue = (*src)->m_iClassname.pszValue;
    v5 = (v3 + start) >> 1;
    if ( pszValue == nullptr )
      pszValue = locale;
    v6 = this->m_Memory.m_pMemory[v5]->m_iClassname.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( _V_stricmp(s1: v6, s2: pszValue) >= 0 )
      break;
    start = v5 + 1;
LABEL_20:
    if ( start > v3 )
      return v3;
  }
  v7 = this->m_Memory.m_pMemory[v5]->m_iClassname.pszValue;
  if ( v7 == nullptr )
    v7 = locale;
  v8 = (*src)->m_iClassname.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  if ( _V_stricmp(s1: v8, s2: v7) < 0 )
  {
    v3 = v5 - 1;
    goto LABEL_20;
  }
  return (v3 + start) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x1010D9D0
// Name: int AimTarget_ListCopy(class CBaseEntity __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AimTarget_ListCopy(CBaseEntity **pList, int listMax)
{
  int m_Size; // esi

  m_Size = g_AimManager.m_targetList.m_Size;
  if ( listMax < g_AimManager.m_targetList.m_Size )
    m_Size = listMax;
  memcpy(
    dst: (unsigned __int8 *)pList,
    src: (unsigned __int8 *)g_AimManager.m_targetList.m_Memory.m_pMemory,
    count: 4 * m_Size);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1010DA10
// Name: public: int CSimThinkManager::ListCopy(class CBaseEntity __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSimThinkManager::ListCopy(CSimThinkManager *this, CBaseEntity **pList, int listMax)
{
  int m_Size; // edi
  int result; // eax
  int v5; // esi
  simthinkentry_t *v6; // edx
  CBaseEntity *m_pEntity; // edx
  CSimThinkManager *v8; // [esp+8h] [ebp-4h]

  v8 = this;
  m_Size = listMax;
  if ( listMax >= this->m_simThinkList.m_Size )
    m_Size = this->m_simThinkList.m_Size;
  result = 0;
  v5 = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = &this->m_simThinkList.m_Memory.m_pMemory[v5];
      if ( v6->nextThinkTick <= gpGlobals->tickcount )
      {
        m_pEntity = (CBaseEntity *)gEntList.m_EntPtrArray[v6->entEntry].m_pEntity;
        if ( m_pEntity != nullptr )
          pList[result++] = m_pEntity;
      }
      if ( ++v5 >= m_Size )
        break;
      this = v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010DA90
// Name: int SimThink_ListCopy(class CBaseEntity __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SimThink_ListCopy(CBaseEntity **pList, int listMax)
{
  return CSimThinkManager::ListCopy(this: &g_SimThinkManager, pList, listMax);
}

//------------------------------------------------------------------------------
// Address: 0x1010DAB0
// Name: public: void CGlobalEntityList::UpdateName(class IHandleEntity __near *,class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::UpdateName(CGlobalEntityList *this, IHandleEntity *pHandleEnt, CBaseHandle hEnt)
{
  int m_Index_low; // edx
  CEntInfo *v4; // esi
  CEntInfo *v5; // ecx
  IHandleEntity *m_pEntity; // ecx
  int v7; // eax
  const char *v8; // ecx

  if ( hEnt.m_Index == -1 )
    m_Index_low = 0x1FFF;
  else
    m_Index_low = LOWORD(hEnt.m_Index);
  v4 = &this->m_EntPtrArray[m_Index_low];
  if ( hEnt.m_Index == -1 || (v5 = &this->m_EntPtrArray[LOWORD(hEnt.m_Index)])->m_SerialNumber != HIWORD(hEnt.m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = v5->m_pEntity;
  v7 = (int)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  v8 = *(const char **)(v7 + 92);
  if ( v8 == nullptr || *v8 == 0 )
    v8 = nullptr;
  v4->m_iClassName.pszValue = v8;
  v4->m_iName.pszValue = *(const char **)(v7 + 204);
}

//------------------------------------------------------------------------------
// Address: 0x1010DB20
// Name: public: void CGlobalEntityList::UpdateName(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::UpdateName(CGlobalEntityList *this, IHandleEntity *pEnt)
{
  CBaseHandle *v3; // eax

  v3 = pEnt->GetRefEHandle(this: pEnt);
  CGlobalEntityList::UpdateName(this, pHandleEnt: pEnt, hEnt: (CBaseHandle)v3->m_Index);
}

//------------------------------------------------------------------------------
// Address: 0x1010DB50
// Name: public: void CGlobalEntityList::PostClientMessagesSent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::PostClientMessagesSent(CGlobalEntityList *this)
{
  int i; // esi
  CBaseEntity *m_pEntity; // ecx

  for ( i = g_PostClientManager.m_list.m_Size - 1; i >= 0; --i )
  {
    m_pEntity = (CBaseEntity *)gEntList.m_EntPtrArray[g_PostClientManager.m_list.m_Memory.m_pMemory[i]].m_pEntity;
    if ( m_pEntity != nullptr )
      CBaseEntity::PostClientMessagesSent(this: m_pEntity);
  }
  g_PostClientManager.m_list.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010DB90
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityProcedural(char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGlobalEntityList::FindEntityProcedural(
        CGlobalEntityList *this,
        const char *szName,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  const char *v5; // esi
  CBaseEntity *v7; // eax
  edict_t *ClientInPVS; // eax
  CBasePlayer *v9; // eax

  if ( *szName != 33 )
    return nullptr;
  v5 = szName + 1;
  if ( szName + 1 == "player" || _V_stricmp(s1: szName + 1, s2: "player") == 0 )
    return UTIL_PlayerByIndex(playerIndex: 1);
  if ( v5 != "pvsplayer" && _V_stricmp(s1: szName + 1, s2: "pvsplayer") != 0 )
  {
    if ( v5 == "activator" || _V_stricmp(s1: szName + 1, s2: "activator") == 0 )
      return (CBasePlayer *)pActivator;
    if ( v5 == "caller" || _V_stricmp(s1: szName + 1, s2: "caller") == 0 )
      return (CBasePlayer *)pCaller;
    if ( FStrEq(sz1: szName + 1, sz2: "picker") )
    {
      if ( UTIL_PlayerByIndex(playerIndex: 1) != nullptr )
      {
        v9 = UTIL_PlayerByIndex(playerIndex: 1);
        return (CBasePlayer *)v9->FindPickerEntity(this: v9);
      }
    }
    else
    {
      if ( FStrEq(sz1: szName + 1, sz2: "self") )
        return (CBasePlayer *)pSearchingEntity;
      _Warning(a1: "Invalid entity search name %s\n", szName);
    }
    return nullptr;
  }
  v7 = pSearchingEntity;
  if ( pSearchingEntity == nullptr )
  {
    v7 = pActivator;
    if ( pActivator == nullptr )
      return UTIL_PlayerByIndex(playerIndex: 1);
  }
  ClientInPVS = UTIL_FindClientInPVS(pEdict: v7->m_Network.m_pPev);
  return (CBasePlayer *)CBaseEntity::Instance(pent: ClientInPVS);
}

//------------------------------------------------------------------------------
// Address: 0x1010DCD0
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByName(class CBaseEntity __near *,char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,class IEntityFindFilter __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGlobalEntityList::FindEntityByName(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        IEntityFindFilter *pFilter)
{
  const CBaseHandle *v9; // eax
  CEntInfo *m_pNext; // esi
  CBaseEntity *m_pEntity; // edi
  const char *pszValue; // eax

  if ( szName == nullptr || *szName == 0 )
    return nullptr;
  if ( *szName == 33 )
  {
    if ( pStartEntity == nullptr )
      return CGlobalEntityList::FindEntityProcedural(this, szName, pSearchingEntity, pActivator, pCaller);
    return nullptr;
  }
  if ( pStartEntity != nullptr )
  {
    v9 = pStartEntity->GetRefEHandle(this: pStartEntity);
    m_pNext = CBaseEntityList::GetEntInfoPtr(this, hEnt: v9)->m_pNext;
  }
  else
  {
    m_pNext = this->m_activeList.m_pHead;
  }
  if ( m_pNext == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pEntity = (CBaseEntity *)m_pNext->m_pEntity;
    if ( m_pNext->m_pEntity != nullptr )
      break;
    DevWarning(a1: "NULL entity in global entity list!\n");
LABEL_18:
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return nullptr;
  }
  pszValue = m_pNext->m_iName.pszValue;
  if ( pszValue == nullptr
    || pszValue != szName && EntityNamesMatchCStrings(pszQuery: szName, pszNameToMatch: m_pNext->m_iName.pszValue) == 0
    || pFilter != nullptr && pFilter->ShouldFindEntity(this: pFilter, a2: m_pEntity) == 0 )
  {
    goto LABEL_18;
  }
  return (CBasePlayer *)m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010DD90
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByModel(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByModel(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szModelName)
{
  unsigned int m_Index; // eax
  CEntInfo *m_pNext; // edi
  const char *v6; // ebx
  IHandleEntity *m_pEntity; // esi
  const char *v8; // eax

  if ( pStartEntity != nullptr )
  {
    m_Index = pStartEntity->GetRefEHandle(this: pStartEntity)->m_Index;
    if ( m_Index == -1 )
      m_pNext = this->m_EntPtrArray[0x1FFF].m_pNext;
    else
      m_pNext = this->m_EntPtrArray[(unsigned __int16)m_Index].m_pNext;
  }
  else
  {
    m_pNext = this->m_activeList.m_pHead;
  }
  if ( m_pNext == nullptr )
    return nullptr;
  v6 = szModelName;
  while ( 1 )
  {
    m_pEntity = m_pNext->m_pEntity;
    if ( m_pNext->m_pEntity != nullptr )
      break;
    DevWarning(a1: "NULL entity in global entity list!\n");
LABEL_16:
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return nullptr;
  }
  if ( m_pEntity[6].__vftable == nullptr
    || *(_DWORD *)((int (__thiscall *)(IHandleEntity *, CBaseEntity **))m_pEntity->__vftable[2].SetRefEHandle)(
                    a1: m_pEntity,
                    a2: &pStartEntity) == 0 )
  {
    goto LABEL_16;
  }
  v8 = *(const char **)((int (__thiscall *)(IHandleEntity *, const char **))m_pEntity->__vftable[2].SetRefEHandle)(
                         a1: m_pEntity,
                         a2: &szModelName);
  if ( v8 == nullptr )
    v8 = locale;
  if ( v8 != v6 && _V_stricmp(s1: v8, s2: v6) != 0 )
    goto LABEL_16;
  return (CBaseEntity *)m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010DE50
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityInSphere(class CBaseEntity __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityInSphere(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const Vector *vecCenter,
        float flRadius)
{
  unsigned int m_Index; // eax
  CEntInfo *m_pNext; // ebx
  IHandleEntity *m_pEntity; // edi
  const Vector *v8; // eax
  const Vector *v10; // [esp-8h] [ebp-24h]
  Vector vecRelativeCenter; // [esp+10h] [ebp-Ch] BYREF

  if ( pStartEntity != nullptr )
  {
    m_Index = pStartEntity->GetRefEHandle(this: pStartEntity)->m_Index;
    if ( m_Index == -1 )
      m_pNext = this->m_EntPtrArray[0x1FFF].m_pNext;
    else
      m_pNext = this->m_EntPtrArray[(unsigned __int16)m_Index].m_pNext;
  }
  else
  {
    m_pNext = this->m_activeList.m_pHead;
  }
  if ( m_pNext == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pEntity = m_pNext->m_pEntity;
    if ( m_pNext->m_pEntity != nullptr )
      break;
    DevWarning(a1: "NULL entity in global entity list!\n");
LABEL_11:
    m_pNext = m_pNext->m_pNext;
    if ( m_pNext == nullptr )
      return nullptr;
  }
  if ( m_pEntity[6].__vftable == nullptr )
    goto LABEL_11;
  CCollisionProperty::WorldToCollisionSpace(
    this: (CCollisionProperty *)&m_pEntity[57],
    in: vecCenter,
    pResult: &vecRelativeCenter);
  v10 = (const Vector *)m_pEntity[57].GetRefEHandle(this: m_pEntity + 57);
  v8 = (const Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity[57].SetRefEHandle)(a1: &m_pEntity[57]);
  if ( !IsBoxIntersectingSphere(boxMin: v8, boxMax: v10, center: &vecRelativeCenter, radius: flRadius) )
    goto LABEL_11;
  return (CBaseEntity *)m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010DF30
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByNameNearest(char const __near *,class Vector const __near &,float,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByNameNearest(
        CGlobalEntityList *this,
        const char *szName,
        const Vector *vecSrc,
        float flRadius,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBasePlayer *i; // esi
  float v8; // xmm1_4
  CBaseEntity *pEntity; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF
  float flMaxDist2; // [esp+14h] [ebp+10h]

  pEntity = nullptr;
  flMaxDist2 = flRadius * flRadius;
  if ( flMaxDist2 == 0.0 )
    flMaxDist2 = 3221225500.0;
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName,
              pSearchingEntity,
              pActivator,
              pCaller,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName,
              pSearchingEntity,
              pActivator,
              pCaller,
              pFilter: nullptr) )
  {
    if ( i->m_Network.m_pPev != nullptr )
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
      v8 = i->m_vecAbsOrigin.y - vecSrc->y;
      if ( flMaxDist2 > (float)((float)((float)((float)(i->m_vecAbsOrigin.x - vecSrc->x)
                                              * (float)(i->m_vecAbsOrigin.x - vecSrc->x))
                                      + (float)(v8 * v8))
                              + (float)((float)(i->m_vecAbsOrigin.z - vecSrc->z)
                                      * (float)(i->m_vecAbsOrigin.z - vecSrc->z))) )
      {
        pEntity = i;
        flMaxDist2 = (float)((float)((float)(i->m_vecAbsOrigin.x - vecSrc->x) * (float)(i->m_vecAbsOrigin.x - vecSrc->x))
                           + (float)(v8 * v8))
                   + (float)((float)(i->m_vecAbsOrigin.z - vecSrc->z) * (float)(i->m_vecAbsOrigin.z - vecSrc->z));
      }
    }
  }
  return pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010E030
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByNameWithin(class CBaseEntity __near *,char const __near *,class Vector const __near &,float,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGlobalEntityList::FindEntityByNameWithin(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName,
        const Vector *vecSrc,
        float flRadius,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBasePlayer *EntityByName; // esi
  float v10; // xmm1_4
  int savedregs; // [esp+0h] [ebp+0h] BYREF
  float flMaxDist2; // [esp+14h] [ebp+14h]

  flMaxDist2 = flRadius * flRadius;
  if ( flMaxDist2 == 0.0 )
    return CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity,
             szName,
             pSearchingEntity,
             pActivator,
             pCaller,
             pFilter: nullptr);
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity,
                   szName,
                   pSearchingEntity,
                   pActivator,
                   pCaller,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( EntityByName->m_Network.m_pPev != nullptr )
    {
      if ( (EntityByName->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByName, a2: (int)&savedregs);
      v10 = EntityByName->m_vecAbsOrigin.y - vecSrc->y;
      if ( flMaxDist2 > (float)((float)((float)((float)(EntityByName->m_vecAbsOrigin.x - vecSrc->x)
                                              * (float)(EntityByName->m_vecAbsOrigin.x - vecSrc->x))
                                      + (float)(v10 * v10))
                              + (float)((float)(EntityByName->m_vecAbsOrigin.z - vecSrc->z)
                                      * (float)(EntityByName->m_vecAbsOrigin.z - vecSrc->z))) )
        break;
    }
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName,
                     pSearchingEntity,
                     pActivator,
                     pCaller,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      return nullptr;
  }
  return EntityByName;
}

//------------------------------------------------------------------------------
// Address: 0x1010E130
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByClassnameNearest(char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByClassnameNearest(
        CGlobalEntityList *this,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  CBaseEntity *EntityByClassname; // esi
  float v5; // xmm1_4
  CBaseEntity *pEntity; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h] BYREF
  float flMaxDist2; // [esp+14h] [ebp+10h]

  pEntity = nullptr;
  flMaxDist2 = flRadius * flRadius;
  if ( flMaxDist2 == 0.0 )
    flMaxDist2 = 3221225500.0;
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName);
  if ( EntityByClassname == nullptr )
    return nullptr;
  do
  {
    if ( EntityByClassname->m_Network.m_pPev != nullptr )
    {
      if ( (EntityByClassname->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: EntityByClassname, a2: (int)&savedregs);
      v5 = EntityByClassname->m_vecAbsOrigin.y - vecSrc->y;
      if ( flMaxDist2 > (float)((float)((float)((float)(EntityByClassname->m_vecAbsOrigin.x - vecSrc->x)
                                              * (float)(EntityByClassname->m_vecAbsOrigin.x - vecSrc->x))
                                      + (float)(v5 * v5))
                              + (float)((float)(EntityByClassname->m_vecAbsOrigin.z - vecSrc->z)
                                      * (float)(EntityByClassname->m_vecAbsOrigin.z - vecSrc->z))) )
      {
        pEntity = EntityByClassname;
        flMaxDist2 = (float)((float)((float)(EntityByClassname->m_vecAbsOrigin.x - vecSrc->x)
                                   * (float)(EntityByClassname->m_vecAbsOrigin.x - vecSrc->x))
                           + (float)(v5 * v5))
                   + (float)((float)(EntityByClassname->m_vecAbsOrigin.z - vecSrc->z)
                           * (float)(EntityByClassname->m_vecAbsOrigin.z - vecSrc->z));
      }
    }
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName);
  }
  while ( EntityByClassname != nullptr );
  return pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1010E210
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityByClassnameWithin(class CBaseEntity __near *,char const __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityByClassnameWithin(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName,
        const Vector *vecSrc,
        float flRadius)
{
  CBaseEntity *EntityByClassname; // edi
  unsigned __int8 m_Value; // al
  float *v8; // eax
  const matrix3x4_t *v9; // eax
  float *v10; // eax
  const Vector *v11; // eax
  const Vector *v12; // [esp-8h] [ebp-24h]
  Vector vecRelativeCenter; // [esp+10h] [ebp-Ch] BYREF

  if ( (float)(flRadius * flRadius) == 0.0 )
    return CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity, szName);
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity, szName);
  if ( EntityByClassname == nullptr )
    return nullptr;
  while ( 1 )
  {
    if ( EntityByClassname->m_Network.m_pPev != nullptr || (EntityByClassname->m_iEFlags & 0x200) != 0 )
    {
      if ( (EntityByClassname->m_Collision.m_usSolidFlags.m_Value & 0x40) != 0
        || (m_Value = EntityByClassname->m_Collision.m_nSolidType.m_Value) == 2
        || m_Value == 0
        || (v8 = (float *)EntityByClassname->m_Collision.GetCollisionAngles(this: &EntityByClassname->m_Collision),
            vec3_angle.x == *v8)
        && vec3_angle.y == v8[1]
        && vec3_angle.z == v8[2] )
      {
        v10 = (float *)EntityByClassname->m_Collision.GetCollisionOrigin(this: &EntityByClassname->m_Collision);
        vecRelativeCenter.x = vecSrc->x - *v10;
        vecRelativeCenter.y = vecSrc->y - v10[1];
        vecRelativeCenter.z = vecSrc->z - v10[2];
      }
      else
      {
        v9 = EntityByClassname->m_Collision.CollisionToWorldTransform(this: &EntityByClassname->m_Collision);
        VectorITransform(in1: &vecSrc->x, in2: v9, out: &vecRelativeCenter.x);
      }
      v12 = EntityByClassname->m_Collision.OBBMaxs(this: &EntityByClassname->m_Collision);
      v11 = EntityByClassname->m_Collision.OBBMins(this: &EntityByClassname->m_Collision);
      if ( IsBoxIntersectingSphere(boxMin: v11, boxMax: v12, center: &vecRelativeCenter, radius: flRadius) )
        break;
    }
    EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                          this: &gEntList,
                          pStartEntity: EntityByClassname,
                          szName);
    if ( EntityByClassname == nullptr )
      return nullptr;
  }
  return EntityByClassname;
}

//------------------------------------------------------------------------------
// Address: 0x1010E3B0
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityGeneric(class CBaseEntity __near *,char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGlobalEntityList::FindEntityGeneric(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBasePlayer *result; // eax

  result = CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity,
             szName,
             pSearchingEntity,
             pActivator,
             pCaller,
             pFilter: nullptr);
  if ( result == nullptr )
    return (CBasePlayer *)CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity, szName);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E3F0
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityGenericWithin(class CBaseEntity __near *,char const __near *,class Vector const __near &,float,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGlobalEntityList::FindEntityGenericWithin(
        CGlobalEntityList *this,
        CBaseEntity *pStartEntity,
        const char *szName,
        const Vector *vecSrc,
        float flRadius,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBasePlayer *result; // eax

  result = CGlobalEntityList::FindEntityByNameWithin(
             this: &gEntList,
             pStartEntity,
             szName,
             vecSrc,
             flRadius,
             pSearchingEntity,
             pActivator,
             pCaller);
  if ( result == nullptr )
    return (CBasePlayer *)CGlobalEntityList::FindEntityByClassnameWithin(
                            this: &gEntList,
                            pStartEntity,
                            szName,
                            vecSrc,
                            flRadius);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E450
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityGenericNearest(char const __near *,class Vector const __near &,float,class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityGenericNearest(
        CGlobalEntityList *this,
        const char *szName,
        const Vector *vecSrc,
        float flRadius,
        CBaseEntity *pSearchingEntity,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller)
{
  CBaseEntity *result; // eax

  result = CGlobalEntityList::FindEntityByNameNearest(
             this: &gEntList,
             szName,
             vecSrc,
             flRadius,
             pSearchingEntity,
             pActivator,
             pCaller);
  if ( result == nullptr )
    return CGlobalEntityList::FindEntityByClassnameNearest(this: &gEntList, szName, vecSrc, flRadius);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E4A0
// Name: public: class CBaseEntity __near * CGlobalEntityList::FindEntityNearestFacing(class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGlobalEntityList::FindEntityNearestFacing(
        CGlobalEntityList *this,
        const Vector *origin,
        const Vector *facing,
        float threshold)
{
  CEntInfo *m_pHead; // ecx
  CBaseEntity *result; // eax
  CBaseEntity *m_pEntity; // esi
  float *v8; // eax
  const char *pszValue; // eax
  const char *v10; // eax
  Vector to_ent; // [esp+0h] [ebp-14h] BYREF
  CBaseEntity *best_ent; // [esp+Ch] [ebp-8h]
  float bestDot; // [esp+10h] [ebp-4h]
  float dot; // [esp+20h] [ebp+Ch]
  const CEntInfo *pInfo; // [esp+24h] [ebp+10h]

  m_pHead = this->m_activeList.m_pHead;
  result = nullptr;
  bestDot = threshold;
  best_ent = nullptr;
  pInfo = m_pHead;
  if ( m_pHead != nullptr )
  {
    do
    {
      m_pEntity = (CBaseEntity *)pInfo->m_pEntity;
      if ( pInfo->m_pEntity != nullptr )
      {
        if ( m_pEntity->m_Network.m_pPev != nullptr )
        {
          v8 = (float *)m_pEntity->WorldSpaceCenter(this: pInfo->m_pEntity);
          to_ent.x = *v8 - origin->x;
          to_ent.y = v8[1] - origin->y;
          to_ent.z = v8[2] - origin->z;
          VectorNormalize(vec: &to_ent);
          dot = (float)((float)(facing->y * to_ent.y) + (float)(facing->x * to_ent.x)) + (float)(facing->z * to_ent.z);
          if ( bestDot < dot )
          {
            pszValue = m_pEntity->m_iClassname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            if ( pszValue != "worldspawn" && _V_stricmp(s1: pszValue, s2: "worldspawn") != 0 )
            {
              v10 = m_pEntity->m_iClassname.pszValue;
              if ( v10 == nullptr )
                v10 = locale;
              if ( v10 != "soundent" && _V_stricmp(s1: v10, s2: "soundent") != 0 )
              {
                bestDot = dot;
                best_ent = m_pEntity;
              }
            }
          }
        }
      }
      else
      {
        DevWarning(a1: "NULL entity in global entity list!\n");
      }
      pInfo = pInfo->m_pNext;
    }
    while ( pInfo != nullptr );
    return best_ent;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010E5F0
// Name: protected: virtual void CGlobalEntityList::OnAddEntity(class IHandleEntity __near *,class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::OnAddEntity(CGlobalEntityList *this, IHandleEntity *pEnt, CBaseHandle handle)
{
  int m_Index_low; // eax
  const CBaseHandle *v5; // ebx
  int i; // esi
  IEntityListener *v7; // ecx

  if ( handle.m_Index == -1 )
    m_Index_low = 0x1FFF;
  else
    m_Index_low = LOWORD(handle.m_Index);
  ++this->m_iNumEnts;
  if ( m_Index_low > this->m_iHighestEnt )
    this->m_iHighestEnt = m_Index_low;
  v5 = pEnt->__vftable[1].GetRefEHandle(this: pEnt);
  if ( v5[6].m_Index != 0 )
    ++this->m_iNumEdicts;
  for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
  {
    v7 = this->m_entityListeners.m_Memory.m_pMemory[i];
    v7->OnEntityCreated(this: v7, a2: (CBaseEntity *)v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E670
// Name: protected: virtual void CGlobalEntityList::OnRemoveEntity(class IHandleEntity __near *,class CBaseHandle)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::OnRemoveEntity(CGlobalEntityList *this, IHandleEntity *pEnt, CBaseHandle handle)
{
  if ( pEnt->__vftable[1].GetRefEHandle(this: pEnt)[6].m_Index != 0 )
    --this->m_iNumEdicts;
  --this->m_iNumEnts;
}

//------------------------------------------------------------------------------
// Address: 0x1010E6B0
// Name: public: void CGlobalEntityList::NotifySpawn(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::NotifySpawn(CGlobalEntityList *this, CBaseEntity *pEnt)
{
  int i; // esi
  IEntityListener *v4; // ecx

  if ( pEnt != nullptr )
  {
    for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
    {
      v4 = this->m_entityListeners.m_Memory.m_pMemory[i];
      v4->OnEntitySpawned(this: v4, a2: pEnt);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E6F0
// Name: public: virtual void CNotifyList::ReportNamedEvent(class CBaseEntity __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::ReportNamedEvent(CNotifyList *this, CBaseEntity *pEntity, const char *pInputName)
{
  int v3; // edi
  entitynotify_t *v5; // eax

  v3 = 0;
  if ( (pEntity->m_iEFlags & 0x40) != 0 && this->m_notifyList.m_Size > 0 )
  {
    do
    {
      v5 = &this->m_notifyList.m_Memory.m_pMemory[v3];
      if ( v5->pWatched == pEntity )
        ((void (__thiscall *)(CBaseEntity *, const char *, CBaseEntity *, CBaseEntity *, _DWORD))v5->pNotify->AcceptInput)(
          a1: v5->pNotify,
          a2: pInputName,
          a3: pEntity,
          a4: pEntity,
          a5: 0);
      ++v3;
    }
    while ( v3 < this->m_notifyList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E780
// Name: public: virtual void CNotifyList::ReportSystemEvent(class CBaseEntity __near *,enum notify_system_event_t,struct notify_system_event_params_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::ReportSystemEvent(
        CNotifyList *this,
        CBaseEntity *pEntity,
        notify_system_event_t eventType,
        const notify_system_event_params_t *params)
{
  int i; // esi
  entitynotify_t *v6; // eax

  if ( (pEntity->m_iEFlags & 0x40) != 0 )
  {
    for ( i = 0; i < this->m_notifyList.m_Size; ++i )
    {
      v6 = &this->m_notifyList.m_Memory.m_pMemory[i];
      if ( v6->pWatched == pEntity )
        v6->pNotify->NotifySystemEvent(this: v6->pNotify, a2: pEntity, a3: eventType, a4: params);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E7D0
// Name: public: void CEntityTouchManager::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityTouchManager::FrameUpdatePostEntityThink(CEntityTouchManager *this)
{
  int m_Size; // edi
  void *v3; // esp
  int v4; // esi
  int v5; // ecx
  unsigned __int8 *m_pMemory; // [esp-8h] [ebp-18h]
  unsigned __int8 v7[12]; // [esp+0h] [ebp-10h] BYREF
  unsigned __int8 *v8; // [esp+Ch] [ebp-4h]

  m_Size = this->m_updateList.m_Size;
  if ( m_Size != 0 )
  {
    v3 = alloca(4 * m_Size);
    m_pMemory = (unsigned __int8 *)this->m_updateList.m_Memory.m_pMemory;
    v8 = v7;
    memcpy(dst: v7, src: m_pMemory, count: 4 * m_Size);
    v4 = 0;
    for ( this->m_updateList.m_Size = 0; v4 < m_Size; ++v4 )
    {
      v5 = *(_DWORD *)&v8[4 * v4];
      if ( (*(_BYTE *)(v5 + 199) & 1) != 0 )
        CBaseEntity::PhysicsCheckForEntityUntouch(this: (CBaseEntity *)v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E840
// Name: public: virtual bool CRespawnEntitiesFilter::ShouldCreateEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRespawnEntitiesFilter::ShouldCreateEntity(CRespawnEntitiesFilter *this, const char *pClassname)
{
  return _V_stricmp(s1: pClassname, s2: "worldspawn") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1010E880
// Name: public: void CSortedEntityList::ReportEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSortedEntityList::ReportEntityList(CSortedEntityList *this)
{
  int v1; // eax
  CSortedEntityList *v2; // esi
  int v3; // edi
  const char *v4; // ebx
  CBaseEntity *v5; // eax
  const char *pszValue; // esi
  int m_Size; // eax
  int i; // [esp+Ch] [ebp-Ch]
  int edicts; // [esp+14h] [ebp-4h]

  v1 = 0;
  v2 = this;
  v3 = 0;
  v4 = locale;
  edicts = 0;
  i = 0;
  if ( this->m_sortedList.m_Size > 0 )
  {
    do
    {
      v5 = v2->m_sortedList.m_Memory.m_pMemory[v1];
      if ( v5 != nullptr )
      {
        if ( v5->m_Network.m_pPev != nullptr )
          ++edicts;
        pszValue = v5->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( pszValue == v4 || _V_stricmp(s1: pszValue, s2: v4) == 0 )
        {
          ++v3;
        }
        else
        {
          if ( v3 != 0 )
            _Msg(a1: "Class: %s (%d)\n", v4, v3);
          v4 = pszValue;
          v3 = 1;
        }
        v2 = this;
      }
      v1 = i + 1;
      i = v1;
    }
    while ( v1 < v2->m_sortedList.m_Size );
    if ( *v4 != 0 && v3 != 0 )
      _Msg(a1: "Class: %s (%d)\n", v4, v3);
  }
  m_Size = v2->m_sortedList.m_Size;
  if ( m_Size != 0 )
    _Msg(a1: "Total %d entities (%d empty, %d edicts)\n", m_Size, v2->m_emptyCount, edicts);
}

//------------------------------------------------------------------------------
// Address: 0x1010E9C0
// Name: public: void CAimTargetManager::RemoveEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAimTargetManager::RemoveEntity(CAimTargetManager *this, CBaseEntity *pEntity)
{
  int m_Size; // esi
  int v3; // eax
  CBaseEntity **i; // edx

  m_Size = this->m_targetList.m_Size;
  v3 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_targetList.m_Memory.m_pMemory; *i != pEntity; ++i )
    {
      if ( ++v3 >= m_Size )
        return;
    }
    if ( v3 >= 0 && v3 < m_Size )
    {
      if ( v3 != m_Size - 1 )
        this->m_targetList.m_Memory.m_pMemory[v3] = this->m_targetList.m_Memory.m_pMemory[m_Size - 1];
      --this->m_targetList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EA10
// Name: public: void CSimThinkManager::RemoveEntinfoIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimThinkManager::RemoveEntinfoIndex(CSimThinkManager *this, int index)
{
  int v2; // eax
  int m_Size; // esi

  v2 = this->m_entinfoIndex[index];
  if ( v2 != 0xFFFF )
  {
    m_Size = this->m_simThinkList.m_Size;
    if ( m_Size > 0 )
    {
      if ( v2 != m_Size - 1 )
        this->m_simThinkList.m_Memory.m_pMemory[v2] = this->m_simThinkList.m_Memory.m_pMemory[m_Size - 1];
      --this->m_simThinkList.m_Size;
    }
    this->m_entinfoIndex[index] = -1;
    if ( v2 < this->m_simThinkList.m_Size )
      this->m_entinfoIndex[this->m_simThinkList.m_Memory.m_pMemory[v2].entEntry] = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EA80
// Name: public: void CGlobalEntityList::CleanupDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::CleanupDeleteList(CGlobalEntityList *this)
{
  int v1; // esi

  g_fInCleanupDelete = true;
  PhysOnCleanupDeleteList();
  v1 = 0;
  for ( g_bDisableEhandleAccess = true; v1 < g_DeleteList.m_Size; ++v1 )
    g_DeleteList.m_Memory.m_pMemory[v1]->Release(this: g_DeleteList.m_Memory.m_pMemory[v1]);
  g_bDisableEhandleAccess = false;
  g_DeleteList.m_Size = 0;
  g_fInCleanupDelete = false;
}

//------------------------------------------------------------------------------
// Address: 0x1010EAE0
// Name: public: int CGlobalEntityList::ResetDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGlobalEntityList::ResetDeleteList(CGlobalEntityList *this)
{
  int result; // eax

  result = g_DeleteList.m_Size;
  g_DeleteList.m_Size = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010EAF0
// Name: public: void CGlobalEntityList::RemoveListenerEntity(class IEntityListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::RemoveListenerEntity(CGlobalEntityList *this, IEntityListener *pListener)
{
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_entityListeners,
    src: (vgui::TreeNode **)&pListener);
}

//------------------------------------------------------------------------------
// Address: 0x1010EB10
// Name: public: void CGlobalEntityList::NotifyRemoveEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::NotifyRemoveEntity(CGlobalEntityList *this, CBaseEntity *pBaseEnt)
{
  int i; // edi
  IEntityListener *v4; // ecx
  unsigned int m_ListByClass; // eax
  EntsByStringList_t *m_pMemory; // ecx
  int v7; // eax
  bool v8; // zf
  EntsByStringList_t *v9; // eax
  CBaseEntity *m_pNextByClass; // eax
  CBaseEntity *m_pPrevByClass; // eax

  if ( pBaseEnt != nullptr )
  {
    for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
    {
      v4 = this->m_entityListeners.m_Memory.m_pMemory[i];
      v4->OnEntityDeleted(this: v4, a2: pBaseEnt);
    }
    m_ListByClass = pBaseEnt->m_ListByClass;
    if ( m_ListByClass != -1 )
    {
      m_pMemory = g_EntsByClassname.m_Buckets.m_Memory.m_pMemory[HIWORD(m_ListByClass)].m_Memory.m_pMemory;
      v7 = (unsigned __int16)pBaseEnt->m_ListByClass;
      v8 = m_pMemory[v7].pHead == pBaseEnt;
      v9 = &m_pMemory[v7];
      if ( v8 )
        v9->pHead = pBaseEnt->m_pNextByClass;
      m_pNextByClass = pBaseEnt->m_pNextByClass;
      if ( m_pNextByClass != nullptr )
        m_pNextByClass->m_pPrevByClass = pBaseEnt->m_pPrevByClass;
      m_pPrevByClass = pBaseEnt->m_pPrevByClass;
      if ( m_pPrevByClass != nullptr )
        m_pPrevByClass->m_pNextByClass = pBaseEnt->m_pNextByClass;
      pBaseEnt->m_pNextByClass = nullptr;
      pBaseEnt->m_pPrevByClass = nullptr;
      pBaseEnt->m_ListByClass = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EBD0
// Name: public: virtual void CNotifyList::RemoveEntity(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::RemoveEntity(CNotifyList *this, CBaseEntity *pNotify, CBaseEntity *pWatched)
{
  int i; // edx
  entitynotify_t *m_pMemory; // eax
  bool v5; // zf
  entitynotify_t *v6; // eax
  int m_Size; // esi

  for ( i = this->m_notifyList.m_Size - 1; i >= 0; --i )
  {
    m_pMemory = this->m_notifyList.m_Memory.m_pMemory;
    v5 = m_pMemory[i].pNotify == pNotify;
    v6 = &m_pMemory[i];
    if ( v5 && v6->pWatched == pWatched )
    {
      m_Size = this->m_notifyList.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_notifyList.m_Memory.m_pMemory[i] = this->m_notifyList.m_Memory.m_pMemory[m_Size - 1];
        --this->m_notifyList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EC20
// Name: public: virtual void CNotifyList::ClearEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::ClearEntity(CNotifyList *this, CBaseEntity *pNotify)
{
  int i; // edx
  entitynotify_t *m_pMemory; // eax
  bool v4; // zf
  entitynotify_t *v5; // eax
  int m_Size; // esi

  for ( i = this->m_notifyList.m_Size - 1; i >= 0; --i )
  {
    m_pMemory = this->m_notifyList.m_Memory.m_pMemory;
    v4 = m_pMemory[i].pNotify == pNotify;
    v5 = &m_pMemory[i];
    if ( v4 || v5->pWatched == pNotify )
    {
      m_Size = this->m_notifyList.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_notifyList.m_Memory.m_pMemory[i] = this->m_notifyList.m_Memory.m_pMemory[m_Size - 1];
        --this->m_notifyList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EC70
// Name: void EntityTouch_Remove(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EntityTouch_Remove(CBaseEntity *pEntity)
{
  int m_Size; // ecx
  int v2; // eax

  m_Size = g_TouchManager.m_updateList.m_Size;
  v2 = 0;
  if ( g_TouchManager.m_updateList.m_Size > 0 )
  {
    while ( g_TouchManager.m_updateList.m_Memory.m_pMemory[v2] != pEntity )
    {
      if ( ++v2 >= g_TouchManager.m_updateList.m_Size )
        return;
    }
    if ( v2 != -1 && g_TouchManager.m_updateList.m_Size > 0 )
    {
      if ( v2 != g_TouchManager.m_updateList.m_Size - 1 )
      {
        g_TouchManager.m_updateList.m_Memory.m_pMemory[v2] = g_TouchManager.m_updateList.m_Memory.m_pMemory[g_TouchManager.m_updateList.m_Size - 1];
        m_Size = g_TouchManager.m_updateList.m_Size;
      }
      g_TouchManager.m_updateList.m_Size = m_Size - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010ECD0
// Name: public: virtual void CEntityListSystem::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityListSystem::FrameUpdatePostEntityThink(CEntityListSystem *this)
{
  CEntInfo *m_pHead; // eax
  int v3; // ebx
  CBaseEntity *m_pEntity; // esi
  CBaseEntity *v5; // edi
  int m_Index; // eax
  CEntInfo *v7; // eax
  CEntInfo *m_pNext; // eax
  signed int m_pPev; // eax
  const char *v10; // eax
  edict_t *v11; // esi
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  CBasePlayer *v14; // eax
  CRespawnEntitiesFilter filter; // [esp+4h] [ebp-4h] BYREF

  CEntityTouchManager::FrameUpdatePostEntityThink(this: &g_TouchManager);
  if ( this->m_bRespawnAllEntities )
  {
    this->m_bRespawnAllEntities = false;
    GlobalEntity_EnableStateUpdates(bEnable: false);
    m_pHead = gEntList.m_activeList.m_pHead;
    v3 = -1;
    if ( gEntList.m_activeList.m_pHead != nullptr )
      m_pEntity = (CBaseEntity *)gEntList.m_activeList.m_pHead->m_pEntity;
    else
      m_pEntity = nullptr;
    if ( m_pEntity != nullptr )
    {
      while ( 1 )
      {
        if ( m_pEntity != nullptr )
        {
          m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
          if ( m_Index == -1 )
            m_Index = 0x1FFF;
          else
            m_Index = (unsigned __int16)m_Index;
          v7 = &gEntList.m_EntPtrArray[m_Index];
          if ( v7 != nullptr )
          {
            m_pNext = v7->m_pNext;
            if ( m_pNext != nullptr )
            {
              v5 = (CBaseEntity *)m_pNext->m_pEntity;
              goto LABEL_18;
            }
          }
        }
        else if ( m_pHead != nullptr )
        {
          v5 = (CBaseEntity *)m_pHead->m_pEntity;
          goto LABEL_18;
        }
        v5 = nullptr;
LABEL_18:
        if ( m_pEntity->IsPlayer(this: m_pEntity) )
        {
          m_pPev = (signed int)m_pEntity->m_Network.m_pPev;
          if ( m_pPev != 0 )
            m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
          v3 = m_pPev;
        }
        if ( (m_pEntity->m_iEFlags & 0x10) == 0 )
          UTIL_Remove(oldObj: m_pEntity);
        m_pEntity = v5;
        if ( v5 == nullptr )
          break;
        m_pHead = gEntList.m_activeList.m_pHead;
      }
    }
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    GlobalEntity_EnableStateUpdates(bEnable: true);
    engine->AllowImmediateEdictReuse(this: engine);
    CNodeEnt::m_nNodeCount = 0;
    filter.__vftable = (CRespawnEntitiesFilter_vtbl *)&CRespawnEntitiesFilter::`vftable';
    v10 = engine->GetMapEntitiesString(this: engine);
    MapEntity_ParseAllEntities(pMapData: v10, pFilter: &filter, bActivateEntities: true);
    if ( v3 >= 0 )
    {
      if ( gpGlobals->pEdicts != nullptr )
        v11 = (gpGlobals->pEdicts[v3].m_fStateFlags & 2) == 0 ? &gpGlobals->pEdicts[v3] : nullptr;
      else
        v11 = nullptr;
      ClientPutInServer(pEdict: v11, playername: "unnamed");
      ClientActive(pEdict: v11, bLoadGame: false);
      pEdicts = v11;
      if ( (v11 != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
        && (m_pUnk = pEdicts->m_pUnk) != nullptr )
      {
        v14 = (CBasePlayer *)m_pUnk->GetBaseEntity(this: m_pUnk);
        SceneManager_ClientActive(player: v14);
      }
      else
      {
        SceneManager_ClientActive(player: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EE90
// Name: public: int CUtlSortVector<class CBaseEntity __near *,class CSortedEntityList::CEntityReportLess>::Insert(class CBaseEntity __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::Insert(
        CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess> *this,
        CBaseEntity *const *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CBaseEntity **m_pMemory; // ecx
  int v8; // eax
  CBaseEntity **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1\\UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1\\UtlSortVector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1010EF60
// Name: public: virtual void CAimTargetManager::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAimTargetManager::OnEntityDeleted(CAimTargetManager *this, CBaseEntity *pEntity)
{
  if ( (pEntity->m_fFlags.m_Value & 0x20000) != 0 )
    CAimTargetManager::RemoveEntity(this, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1010EF80
// Name: public: void CSimThinkManager::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimThinkManager::Clear(CSimThinkManager *this)
{
  this->m_simThinkList.m_Size = 0;
  if ( this->m_simThinkList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_simThinkList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_simThinkList.m_Memory.m_pMemory);
      this->m_simThinkList.m_Memory.m_pMemory = nullptr;
    }
    this->m_simThinkList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_simThinkList.m_pElements = this->m_simThinkList.m_Memory.m_pMemory;
  memset(this->m_entinfoIndex, 0xFFu, sizeof(this->m_entinfoIndex));
}

//------------------------------------------------------------------------------
// Address: 0x1010EFF0
// Name: public: void CGlobalEntityList::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::Clear(CGlobalEntityList *this)
{
  CEntInfo *m_pHead; // eax
  unsigned int v3; // esi
  IHandleEntity *m_pEntity; // eax
  IMDLCache *v5; // ebx
  CEntInfo *m_pNext; // eax
  IServerNetworkable **m_pMemory; // eax
  int m_Size; // ecx
  int v9; // eax
  IServerNetworkable *oldObj; // [esp+8h] [ebp-4h]

  m_pHead = this->m_activeList.m_pHead;
  this->m_bClearingEntities = true;
  if ( m_pHead != nullptr )
  {
    v3 = (((char *)m_pHead - (char *)this - 4) / 24)
       | (this->m_EntPtrArray[((char *)m_pHead - (char *)this - 4) / 24].m_SerialNumber << 16);
    while ( v3 != -1 )
    {
      if ( this->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3) )
      {
        m_pEntity = this->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          oldObj = (IServerNetworkable *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[1].SetRefEHandle)(a1: this->m_EntPtrArray[(unsigned __int16)v3].m_pEntity);
          if ( oldObj != nullptr )
          {
            v5 = mdlcache;
            mdlcache->BeginLock(this: mdlcache);
            UTIL_Remove(oldObj);
            v5->EndLock(this: v5);
          }
        }
      }
      m_pNext = this->m_EntPtrArray[(unsigned __int16)v3].m_pNext;
      if ( m_pNext != nullptr )
        v3 = (((char *)m_pNext - (char *)this - 4) / 24)
           | (this->m_EntPtrArray[((char *)m_pNext - (char *)this - 4) / 24].m_SerialNumber << 16);
      else
        v3 = -1;
    }
  }
  CGlobalEntityList::CleanupDeleteList(this);
  m_pMemory = g_DeleteList.m_Memory.m_pMemory;
  g_DeleteList.m_Size = 0;
  if ( g_DeleteList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DeleteList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DeleteList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_DeleteList.m_Memory.m_pMemory = nullptr;
    }
    g_DeleteList.m_Memory.m_nAllocationCount = 0;
  }
  m_Size = g_EntsByClassname.m_Buckets.m_Size;
  g_DeleteList.m_pElements = m_pMemory;
  if ( g_EntsByClassname.m_Buckets.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      g_EntsByClassname.m_Buckets.m_Memory.m_pMemory[v9++].m_Size = 0;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CBaseEntity::m_nDebugPlayer = -1;
  CBaseEntity::m_bInDebugSelect = false;
  this->m_iHighestEnt = 0;
  this->m_iNumEnts = 0;
  this->m_bClearingEntities = false;
}

//------------------------------------------------------------------------------
// Address: 0x1010F170
// Name: public: void CNotifyList::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::LevelShutdownPreEntity(CNotifyList *this)
{
  entitynotify_t *m_pMemory; // ecx
  vgui::TreeNode *src; // [esp+8h] [ebp-4h] BYREF

  if ( this != nullptr )
    src = (vgui::TreeNode *)&this->IEntityListener;
  else
    src = nullptr;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&gEntList.m_entityListeners,
    &src);
  this->m_notifyList.m_Size = 0;
  if ( this->m_notifyList.m_Memory.m_nGrowSize < 0 )
  {
    this->m_notifyList.m_pElements = this->m_notifyList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_notifyList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_notifyList.m_Memory.m_pMemory);
      this->m_notifyList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_notifyList.m_Memory.m_pMemory;
    this->m_notifyList.m_Memory.m_nAllocationCount = 0;
    this->m_notifyList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F1E0
// Name: public: virtual void CEntityTouchManager::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityTouchManager::OnEntityDeleted(CEntityTouchManager *this, CBaseEntity *pEntity)
{
  int m_Size; // esi
  int v3; // eax
  CBaseEntity **i; // edx

  if ( (pEntity->m_iEFlags & 0x1000000) != 0 )
  {
    m_Size = this->m_updateList.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      for ( i = this->m_updateList.m_Memory.m_pMemory; *i != pEntity; ++i )
      {
        if ( ++v3 >= m_Size )
          return;
      }
      if ( v3 >= 0 && v3 < m_Size )
      {
        if ( v3 != m_Size - 1 )
          this->m_updateList.m_Memory.m_pMemory[v3] = this->m_updateList.m_Memory.m_pMemory[m_Size - 1];
        --this->m_updateList.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F240
// Name: public: virtual void CEntityListSystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityListSystem::LevelShutdownPreEntity(CEntityListSystem *this)
{
  CNotifyList::LevelShutdownPreEntity(this: &g_NotifyList);
}

//------------------------------------------------------------------------------
// Address: 0x1010F250
// Name: public: virtual void CEntityListSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityListSystem::LevelShutdownPostEntity(CEntityListSystem *this)
{
  CBaseEntity **m_pMemory; // eax
  CBaseEntity **v2; // eax
  unsigned __int16 *v3; // eax
  CBaseEntityClassList *i; // esi
  vgui::TreeNode *src; // [esp+8h] [ebp-4h] BYREF

  src = (vgui::TreeNode *)&g_TouchManager;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&gEntList.m_entityListeners,
    &src);
  m_pMemory = g_TouchManager.m_updateList.m_Memory.m_pMemory;
  g_TouchManager.m_updateList.m_Size = 0;
  if ( g_TouchManager.m_updateList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TouchManager.m_updateList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TouchManager.m_updateList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_TouchManager.m_updateList.m_Memory.m_pMemory = nullptr;
    }
    g_TouchManager.m_updateList.m_Memory.m_nAllocationCount = 0;
  }
  g_TouchManager.m_updateList.m_pElements = m_pMemory;
  src = (vgui::TreeNode *)&g_AimManager;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&gEntList.m_entityListeners,
    &src);
  v2 = g_AimManager.m_targetList.m_Memory.m_pMemory;
  g_AimManager.m_targetList.m_Size = 0;
  if ( g_AimManager.m_targetList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AimManager.m_targetList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_AimManager.m_targetList.m_Memory.m_pMemory);
      v2 = nullptr;
      g_AimManager.m_targetList.m_Memory.m_pMemory = nullptr;
    }
    g_AimManager.m_targetList.m_Memory.m_nAllocationCount = 0;
  }
  g_AimManager.m_targetList.m_pElements = v2;
  v3 = g_PostClientManager.m_list.m_Memory.m_pMemory;
  g_PostClientManager.m_list.m_Size = 0;
  if ( g_PostClientManager.m_list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_PostClientManager.m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_PostClientManager.m_list.m_Memory.m_pMemory);
      v3 = nullptr;
      g_PostClientManager.m_list.m_Memory.m_pMemory = nullptr;
    }
    g_PostClientManager.m_list.m_Memory.m_nAllocationCount = 0;
  }
  g_PostClientManager.m_list.m_pElements = v3;
  src = (vgui::TreeNode *)&g_SimThinkManager;
  CUtlVector<CHostage *,CUtlMemory<CHostage *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&gEntList.m_entityListeners,
    &src);
  CSimThinkManager::Clear(this: &g_SimThinkManager);
  for ( i = s_pClassLists; i != nullptr; i = i->m_pNextClassList )
    i->LevelShutdownPostEntity(this: i);
}

//------------------------------------------------------------------------------
// Address: 0x1010F3C0
// Name: public: void CEntityTouchManager::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityTouchManager::AddEntity(CEntityTouchManager *this, CBaseEntity *pEntity)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_updateList; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( (pEntity->m_iEFlags & 1) == 0 )
  {
    m_nAllocationCount = this->m_updateList.m_Memory.m_nAllocationCount;
    p_m_updateList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_updateList;
    m_Size = this->m_updateList.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_updateList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_updateList[1].m_pMemory;
    m_pMemory = p_m_updateList->m_pMemory;
    v6 = (int)p_m_updateList[1].m_pMemory - m_Size - 1;
    p_m_updateList[1].m_nAllocationCount = (int)p_m_updateList->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_updateList->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (vgui::TreeNode *)pEntity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F430
// Name: public: virtual void CSimThinkManager::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimThinkManager::OnEntityDeleted(CSimThinkManager *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax

  m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  if ( m_Index == -1 )
    CSimThinkManager::RemoveEntinfoIndex(this, index: 0x1FFF);
  else
    CSimThinkManager::RemoveEntinfoIndex(this, index: (unsigned __int16)m_Index);
}

//------------------------------------------------------------------------------
// Address: 0x1010F470
// Name: public: void CSimThinkManager::EntityChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimThinkManager::EntityChanged(CSimThinkManager *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // esi
  int m_iEFlags; // eax
  int v5; // ecx
  unsigned __int16 v6; // ax
  simthinkentry_t *v7; // esi
  simthinkentry_t *v8; // esi

  if ( (pEntity->m_iEFlags & 1) == 0 )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    if ( m_Index != -1 )
    {
      m_iEFlags = pEntity->m_iEFlags;
      if ( (m_iEFlags & 0x400000) != 0 && (m_iEFlags & 0x800000) != 0 )
      {
        CSimThinkManager::RemoveEntinfoIndex(this, index: (unsigned __int16)m_Index);
      }
      else
      {
        v5 = this->m_entinfoIndex[(unsigned __int16)m_Index];
        if ( (_WORD)v5 == 0xFFFF )
        {
          v6 = CUtlVector<simthinkentry_t,CUtlMemory<simthinkentry_t,int>>::AddToTail(this: &this->m_simThinkList);
          this->m_entinfoIndex[(unsigned __int16)m_Index] = v6;
          this->m_simThinkList.m_Memory.m_pMemory[v6].entEntry = m_Index;
          this->m_simThinkList.m_Memory.m_pMemory[this->m_entinfoIndex[(unsigned __int16)m_Index]].nextThinkTick = 0;
          if ( (pEntity->m_iEFlags & 0x800000) != 0 )
          {
            v7 = &this->m_simThinkList.m_Memory.m_pMemory[this->m_entinfoIndex[(unsigned __int16)m_Index]];
            v7->nextThinkTick = CBaseEntity::GetFirstThinkTick(this: pEntity);
          }
        }
        else if ( (m_iEFlags & 0x800000) != 0 )
        {
          v8 = &this->m_simThinkList.m_Memory.m_pMemory[v5];
          v8->nextThinkTick = CBaseEntity::GetFirstThinkTick(this: pEntity);
        }
        else
        {
          this->m_simThinkList.m_Memory.m_pMemory[v5].nextThinkTick = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F580
// Name: void SimThink_EntityChanged(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimThink_EntityChanged(CBaseEntity *pEntity)
{
  CSimThinkManager::EntityChanged(this: &g_SimThinkManager, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1010F5A0
// Name: public: void CPostClientMessageManager::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostClientMessageManager::AddEntity(CPostClientMessageManager *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // eax
  __int16 v4; // bx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  unsigned __int16 *m_pMemory; // ecx
  int v8; // eax
  unsigned __int16 *v9; // eax

  m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
  if ( m_Index == -1 )
    v4 = 0x1FFF;
  else
    v4 = m_Index;
  m_nAllocationCount = this->m_list.m_Memory.m_nAllocationCount;
  m_Size = this->m_list.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow((CUtlMemory<wchar_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_list.m_Size;
  m_pMemory = this->m_list.m_Memory.m_pMemory;
  v8 = this->m_list.m_Size - m_Size - 1;
  this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v8);
  v9 = &this->m_list.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1010F620
// Name: public: void CGlobalEntityList::AddToDeleteList(class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::AddToDeleteList(CGlobalEntityList *this, IServerNetworkable *ent)
{
  int v2; // eax
  int m_Size; // eax
  int v4; // esi
  IServerNetworkable **m_pMemory; // ecx
  int v6; // eax
  IServerNetworkable **v7; // eax

  if ( ent != nullptr )
  {
    v2 = ent->GetEntityHandle(this: ent);
    if ( *(_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2) != -1 )
    {
      m_Size = g_DeleteList.m_Size;
      v4 = g_DeleteList.m_Size;
      if ( g_DeleteList.m_Size + 1 > g_DeleteList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&g_DeleteList,
          num: g_DeleteList.m_Size - g_DeleteList.m_Memory.m_nAllocationCount + 1);
        m_Size = g_DeleteList.m_Size;
      }
      m_pMemory = g_DeleteList.m_Memory.m_pMemory;
      g_DeleteList.m_Size = m_Size + 1;
      v6 = m_Size - v4;
      g_DeleteList.m_pElements = g_DeleteList.m_Memory.m_pMemory;
      if ( v6 > 0 )
      {
        _V_memmove(
          dest: &g_DeleteList.m_Memory.m_pMemory[v4 + 1],
          src: &g_DeleteList.m_Memory.m_pMemory[v4],
          count: 4 * v6);
        m_pMemory = g_DeleteList.m_Memory.m_pMemory;
      }
      v7 = &m_pMemory[v4];
      if ( v7 != nullptr )
        *v7 = ent;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F6B0
// Name: public: void CGlobalEntityList::AddListenerEntity(class IEntityListener __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::AddListenerEntity(CGlobalEntityList *this, IEntityListener *pListener)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_entityListeners; // esi
  int m_Size; // ecx
  int v4; // eax
  IEntityListener **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_entityListeners = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_entityListeners;
  m_Size = this->m_entityListeners.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IEntityListener **)p_m_entityListeners->m_pMemory;
  while ( *m_pMemory != pListener )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 < 0 )
  {
LABEL_7:
    m_nAllocationCount = p_m_entityListeners->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_entityListeners, num: m_Size - m_nAllocationCount + 1);
    ++p_m_entityListeners[1].m_pMemory;
    v8 = p_m_entityListeners->m_pMemory;
    v9 = (int)p_m_entityListeners[1].m_pMemory - v7 - 1;
    p_m_entityListeners[1].m_nAllocationCount = (int)p_m_entityListeners->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_entityListeners->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (vgui::TreeNode *)pListener;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F740
// Name: public: void CGlobalEntityList::ReportEntityFlagsChanged(class CBaseEntity __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::ReportEntityFlagsChanged(
        CGlobalEntityList *this,
        CBaseEntity *pEntity,
        unsigned int flagsOld,
        unsigned int flagsNow)
{
  if ( (pEntity->m_iEFlags & 1) == 0 && ((flagsNow ^ flagsOld) & 0x20000) != 0 )
  {
    if ( (flagsNow & (flagsNow ^ flagsOld) & 0x20000) != 0 )
      CEntityTouchManager::AddEntity(this: (CEntityTouchManager *)&g_AimManager, pEntity);
    if ( (flagsOld & (flagsNow ^ flagsOld) & 0x20000) != 0 )
      CAimTargetManager::RemoveEntity(this: &g_AimManager, pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F7A0
// Name: public: void CGlobalEntityList::AddPostClientMessageEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::AddPostClientMessageEntity(CGlobalEntityList *this, CBaseEntity *pEntity)
{
  CPostClientMessageManager::AddEntity(this: &g_PostClientManager, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1010F7B0
// Name: public: virtual void CNotifyList::AddEntity(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNotifyList::AddEntity(CNotifyList *this, CBaseEntity *pNotify, CBaseEntity *pWatched)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *p_m_notifyList; // esi
  int m_Size; // edi
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v7; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v8; // eax

  pWatched->m_iEFlags |= 0x40u;
  m_nAllocationCount = this->m_notifyList.m_Memory.m_nAllocationCount;
  p_m_notifyList = (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&this->m_notifyList;
  m_Size = this->m_notifyList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      this: p_m_notifyList,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_notifyList[1].m_pMemory;
  m_pMemory = p_m_notifyList->m_pMemory;
  v7 = (int)p_m_notifyList[1].m_pMemory - m_Size - 1;
  p_m_notifyList[1].m_nAllocationCount = (int)p_m_notifyList->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v7);
  v8 = &p_m_notifyList->m_pMemory[m_Size];
  v8->m_pData = (vgui::BuildGroup *)pWatched;
  *(_DWORD *)v8 = pNotify;
}

//------------------------------------------------------------------------------
// Address: 0x1010F820
// Name: void EntityTouch_Add(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EntityTouch_Add(CBaseEntity *pEntity)
{
  CEntityTouchManager::AddEntity(this: &g_TouchManager, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1010F840
// Name: report_entities
// Source: json
//------------------------------------------------------------------------------
void __cdecl report_entities()
{
  CBaseEntity *m_pEntity; // esi
  int m_Index; // eax
  CEntInfo *v2; // eax
  CBaseEntity **m_pNext; // eax
  CSortedEntityList list; // [esp+0h] [ebp-24h] BYREF
  CBaseEntity *src; // [esp+20h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    memset(&list, 0, 25);
    list.m_emptyCount = 0;
    if ( gEntList.m_activeList.m_pHead != nullptr )
      m_pEntity = (CBaseEntity *)gEntList.m_activeList.m_pHead->m_pEntity;
    else
      m_pEntity = nullptr;
    if ( m_pEntity != nullptr )
    {
      do
      {
        src = m_pEntity;
        CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::Insert(this: &list.m_sortedList, &src);
        m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
        if ( m_Index == -1 )
          m_Index = 0x1FFF;
        else
          m_Index = (unsigned __int16)m_Index;
        v2 = &gEntList.m_EntPtrArray[m_Index];
        if ( v2 == nullptr )
          break;
        m_pNext = (CBaseEntity **)v2->m_pNext;
        if ( m_pNext == nullptr )
          break;
        m_pEntity = *m_pNext;
      }
      while ( *m_pNext != nullptr );
    }
    CSortedEntityList::ReportEntityList(this: &list);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F8E0
// Name: report_touchlinks
// Source: json
//------------------------------------------------------------------------------
void __cdecl report_touchlinks(const CCommand *args)
{
  IHandleEntity *m_pEntity; // ecx
  int m_nArgc; // eax
  CBaseEntity *v3; // edi
  unsigned int *DataObject; // eax
  unsigned int *v5; // ebx
  unsigned int *v6; // esi
  unsigned int v7; // eax
  CBaseEntity *v8; // ecx
  int m_Index; // eax
  CEntInfo *v10; // eax
  CBaseEntity **m_pNext; // eax
  CSortedEntityList list; // [esp+0h] [ebp-28h] BYREF
  CBaseEntity *src; // [esp+20h] [ebp-8h] BYREF
  const char *pClassname; // [esp+24h] [ebp-4h]

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    memset(&list, 0, 25);
    list.m_emptyCount = 0;
    if ( gEntList.m_activeList.m_pHead != nullptr )
      m_pEntity = gEntList.m_activeList.m_pHead->m_pEntity;
    else
      m_pEntity = nullptr;
    m_nArgc = args->m_nArgc;
    v3 = (CBaseEntity *)m_pEntity;
    pClassname = nullptr;
    if ( m_nArgc > 1 )
      pClassname = args->m_ppArgv[1];
    if ( m_pEntity != nullptr )
    {
      do
      {
        if ( pClassname == nullptr
          || v3->m_iClassname.pszValue == pClassname
          || CBaseEntity::ClassMatchesComplex(this: v3, pszClassOrWildcard: pClassname) != 0 )
        {
          DataObject = (unsigned int *)CBaseEntity::GetDataObject(this: v3, type: 1);
          v5 = DataObject;
          if ( DataObject != nullptr )
          {
            v6 = (unsigned int *)DataObject[2];
            if ( v6 != DataObject )
            {
              do
              {
                v7 = *v6;
                if ( *v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
                  v8 = nullptr;
                else
                  v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
                src = v8;
                if ( v8 != nullptr )
                  CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::Insert(
                    this: &list.m_sortedList,
                    &src);
                else
                  ++list.m_emptyCount;
                v6 = (unsigned int *)v6[2];
              }
              while ( v6 != v5 );
            }
          }
        }
        m_Index = v3->GetRefEHandle(this: v3)->m_Index;
        if ( m_Index == -1 )
          m_Index = 0x1FFF;
        else
          m_Index = (unsigned __int16)m_Index;
        v10 = &gEntList.m_EntPtrArray[m_Index];
        if ( v10 == nullptr )
          break;
        m_pNext = (CBaseEntity **)v10->m_pNext;
        if ( m_pNext == nullptr )
          break;
        v3 = *m_pNext;
      }
      while ( *m_pNext != nullptr );
    }
    CSortedEntityList::ReportEntityList(this: &list);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FA10
// Name: report_simthinklist
// Source: json
//------------------------------------------------------------------------------
void __cdecl report_simthinklist()
{
  int v0; // edi
  int v1; // esi
  CBaseEntity *pList[8192]; // [esp+0h] [ebp-8024h] BYREF
  CSortedEntityList v3; // [esp+8000h] [ebp-24h] BYREF
  CBaseEntity *src; // [esp+8020h] [ebp-4h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    v0 = CSimThinkManager::ListCopy(this: &g_SimThinkManager, pList, listMax: 0x2000);
    v1 = 0;
    memset(&v3, 0, 25);
    v3.m_emptyCount = 0;
    if ( v0 > 0 )
    {
      do
      {
        if ( pList[v1] != nullptr )
        {
          src = pList[v1];
          CUtlSortVector<CBaseEntity *,CSortedEntityList::CEntityReportLess>::Insert(this: &v3.m_sortedList, &src);
        }
        ++v1;
      }
      while ( v1 < v0 );
    }
    CSortedEntityList::ReportEntityList(this: &v3);
    if ( v3.m_sortedList.m_Memory.m_nGrowSize >= 0 && v3.m_sortedList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3.m_sortedList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FAB0
// Name: public: void CAimTargetManager::ForceRepopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAimTargetManager::ForceRepopulateList(CAimTargetManager *this)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_targetList; // esi
  IHandleEntity *m_pEntity; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v5; // ecx
  int v6; // eax
  IHandleEntity **v7; // eax
  int m_Index; // eax
  CEntInfo *v9; // eax
  IHandleEntity **p_m_pEntity; // eax

  p_m_targetList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_targetList;
  this->m_targetList.m_Size = 0;
  if ( this->m_targetList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_targetList->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_targetList->m_pMemory);
      p_m_targetList->m_pMemory = nullptr;
    }
    p_m_targetList->m_nAllocationCount = 0;
  }
  p_m_targetList[1].m_nAllocationCount = (int)p_m_targetList->m_pMemory;
  if ( gEntList.m_activeList.m_pHead != nullptr )
    m_pEntity = gEntList.m_activeList.m_pHead->m_pEntity;
  else
    m_pEntity = nullptr;
  if ( m_pEntity != nullptr )
  {
    do
    {
      if ( ((int)m_pEntity[50].__vftable & 0x20000) != 0 && ((int)m_pEntity[49].__vftable & 1) == 0 )
      {
        m_pMemory = p_m_targetList[1].m_pMemory;
        m_nAllocationCount = p_m_targetList->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: p_m_targetList, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_targetList[1].m_pMemory;
        v5 = p_m_targetList->m_pMemory;
        v6 = (char *)p_m_targetList[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_targetList[1].m_nAllocationCount = (int)p_m_targetList->m_pMemory;
        if ( v6 > 0 )
          _V_memmove(dest: &v5[(_DWORD)m_pMemory + 1], src: &v5[(_DWORD)m_pMemory], count: 4 * v6);
        v7 = (IHandleEntity **)&p_m_targetList->m_pMemory[(_DWORD)m_pMemory];
        if ( v7 != nullptr )
          *v7 = m_pEntity;
      }
      m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      if ( m_Index == -1 )
        m_Index = 0x1FFF;
      else
        m_Index = (unsigned __int16)m_Index;
      v9 = &gEntList.m_EntPtrArray[m_Index];
      if ( v9 == nullptr )
        break;
      p_m_pEntity = &v9->m_pNext->m_pEntity;
      if ( p_m_pEntity == nullptr )
        break;
      m_pEntity = *p_m_pEntity;
    }
    while ( *p_m_pEntity != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FBB0
// Name: public: virtual void CAimTargetManager::OnEntitySpawned(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAimTargetManager::OnEntitySpawned(CAimTargetManager *this, CBaseEntity *pEntity)
{
  if ( (pEntity->m_fFlags.m_Value & 0x20000) != 0 )
  {
    CAimTargetManager::RemoveEntity(this, pEntity);
    CEntityTouchManager::AddEntity((CEntityTouchManager *)this, pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FBE0
// Name: void AimTarget_ForceRepopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AimTarget_ForceRepopulateList()
{
  CAimTargetManager::ForceRepopulateList(this: &g_AimManager);
}

//------------------------------------------------------------------------------
// Address: 0x1010FBF0
// Name: public: void CGlobalEntityList::NotifyCreateEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlobalEntityList::NotifyCreateEntity(CGlobalEntityList *this, CBaseEntity *pEnt)
{
  CBaseEntity *v2; // edi
  const char *pszValue; // eax
  unsigned int v5; // eax
  unsigned int v6; // esi
  EntsByStringList_t *v7; // ecx
  CBaseEntity *pHead; // eax
  int i; // esi
  IEntityListener *v10; // ecx
  EntsByStringList_t dummyEntry; // [esp+8h] [ebp-Ch] BYREF
  unsigned int pBucket; // [esp+10h] [ebp-4h] BYREF

  v2 = pEnt;
  if ( pEnt != nullptr )
  {
    pszValue = pEnt->m_iClassname.pszValue;
    if ( pszValue == nullptr || *pszValue == 0 )
      pszValue = nullptr;
    dummyEntry.iszStr.pszValue = pszValue;
    dummyEntry.pHead = nullptr;
    pEnt = nullptr;
    if ( CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs>::DoFind(
           this: &g_EntsByClassname,
           src: &dummyEntry,
           &pBucket,
           pIndex: (int *)&pEnt) != 0 )
    {
      v5 = (unsigned int)pEnt | (pBucket << 16);
    }
    else
    {
      v6 = pBucket;
      v5 = (v6 << 16)
         | CUtlVector<CEntityDataInstantiator<physicspushlist_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<physicspushlist_t>::HashEntry,int>>::InsertBefore(
             this: (CUtlVector<AI_NamespaceAddInfo_t,CUtlMemory<AI_NamespaceAddInfo_t,int> > *)&g_EntsByClassname.m_Buckets.m_Memory.m_pMemory[pBucket],
             elem: g_EntsByClassname.m_Buckets.m_Memory.m_pMemory[pBucket].m_Size,
             src: (const AI_NamespaceAddInfo_t *)&dummyEntry);
    }
    v7 = &g_EntsByClassname.m_Buckets.m_Memory.m_pMemory[HIWORD(v5)].m_Memory.m_pMemory[(unsigned __int16)v5];
    v2->m_ListByClass = v5;
    pHead = v7->pHead;
    if ( pHead != nullptr )
    {
      pHead->m_pPrevByClass = v2;
      v2->m_pNextByClass = v7->pHead;
    }
    v7->pHead = v2;
    for ( i = this->m_entityListeners.m_Size - 1; i >= 0; --i )
    {
      v10 = this->m_entityListeners.m_Memory.m_pMemory[i];
      v10->OnEntityCreated(this: v10, a2: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FCD0
// Name: public: virtual void CEntityListSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityListSystem::LevelInitPreEntity(CEntityListSystem *this)
{
  CBaseEntity **m_pMemory; // eax
  CBaseEntity **v2; // eax

  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &g_NotifyList.IEntityListener);
  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &g_TouchManager);
  m_pMemory = g_TouchManager.m_updateList.m_Memory.m_pMemory;
  g_TouchManager.m_updateList.m_Size = 0;
  if ( g_TouchManager.m_updateList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_TouchManager.m_updateList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_TouchManager.m_updateList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_TouchManager.m_updateList.m_Memory.m_pMemory = nullptr;
    }
    g_TouchManager.m_updateList.m_Memory.m_nAllocationCount = 0;
  }
  g_TouchManager.m_updateList.m_pElements = m_pMemory;
  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &g_AimManager);
  v2 = g_AimManager.m_targetList.m_Memory.m_pMemory;
  g_AimManager.m_targetList.m_Size = 0;
  if ( g_AimManager.m_targetList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_AimManager.m_targetList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_AimManager.m_targetList.m_Memory.m_pMemory);
      v2 = nullptr;
      g_AimManager.m_targetList.m_Memory.m_pMemory = nullptr;
    }
    g_AimManager.m_targetList.m_Memory.m_nAllocationCount = 0;
  }
  g_AimManager.m_targetList.m_pElements = v2;
  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &g_SimThinkManager);
}
