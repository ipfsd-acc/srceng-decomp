// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/eventlist.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D2620
// Name: void EventList_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_Init()
{
  g_HighestEvent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100D2630
// Name: int EventList_GetEventType(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_GetEventType(int eventIndex)
{
  int v1; // eax
  eventlist_t *i; // ecx
  eventlist_t *v4; // eax

  v1 = 0;
  if ( g_EventList.m_Size <= 0 )
    return -1;
  for ( i = g_EventList.m_Memory.m_pMemory; i->eventIndex != eventIndex; ++i )
  {
    if ( ++v1 >= g_EventList.m_Size )
      return -1;
  }
  v4 = &g_EventList.m_Memory.m_pMemory[v1];
  if ( v4 != nullptr )
    return v4->iType;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2680
// Name: int EventList_IndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_IndexForName(const char *pszEventName)
{
  int StringID; // eax
  eventlist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && (v2 = &g_EventList.m_Memory.m_pMemory[StringID]) != nullptr )
    return v2->eventIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100D26B0
// Name: void EventList_Free(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_Free()
{
  eventlist_t *m_pMemory; // eax

  CStringRegistry::ClearStrings(this: &g_EventStrings);
  g_EventList.m_Size = 0;
  if ( g_EventList.m_Memory.m_nGrowSize < 0 )
  {
    ++g_nEventListVersion;
    g_EventList.m_pElements = g_EventList.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_EventList.m_Memory.m_pMemory;
    if ( g_EventList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_EventList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_EventList.m_Memory.m_pMemory = nullptr;
    }
    ++g_nEventListVersion;
    g_EventList.m_Memory.m_nAllocationCount = 0;
    g_EventList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D2720
// Name: struct eventlist_t __near * EventList_AddEventEntry(char const __near *,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
eventlist_t *__cdecl EventList_AddEventEntry(const char *pName, int iEventIndex, bool isPrivate, int iType)
{
  int m_Size; // eax
  int v5; // esi
  eventlist_t *m_pMemory; // ecx
  int v7; // eax
  eventlist_t *v8; // edi
  eventlist_t *result; // eax

  m_Size = g_EventList.m_Size;
  v5 = g_EventList.m_Size;
  if ( g_EventList.m_Size + 1 > g_EventList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&g_EventList,
      num: g_EventList.m_Size - g_EventList.m_Memory.m_nAllocationCount + 1);
    m_Size = g_EventList.m_Size;
  }
  m_pMemory = g_EventList.m_Memory.m_pMemory;
  g_EventList.m_Size = m_Size + 1;
  v7 = m_Size - v5;
  g_EventList.m_pElements = g_EventList.m_Memory.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(dest: &g_EventList.m_Memory.m_pMemory[v5 + 1], src: &g_EventList.m_Memory.m_pMemory[v5], count: 12 * v7);
    m_pMemory = g_EventList.m_Memory.m_pMemory;
  }
  v8 = &m_pMemory[v5];
  v8->eventIndex = iEventIndex;
  v8->stringKey = CStringRegistry::AddString(this: &g_EventStrings, stringText: pName, stringID: v5);
  v8->isPrivate = isPrivate;
  v8->iType = iType;
  result = v8;
  if ( iEventIndex > g_HighestEvent )
    g_HighestEvent = iEventIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D27D0
// Name: bool EventList_RegisterSharedEvent(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EventList_RegisterSharedEvent(const char *pszEventName, int iEventIndex, int iType)
{
  int StringID; // eax
  int v4; // eax
  eventlist_t *m_pMemory; // ecx

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && &g_EventList.m_Memory.m_pMemory[StringID] != nullptr )
    return 0;
  v4 = 0;
  if ( g_EventList.m_Size > 0 )
  {
    m_pMemory = g_EventList.m_Memory.m_pMemory;
    while ( m_pMemory->eventIndex != iEventIndex )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= g_EventList.m_Size )
        goto LABEL_7;
    }
    if ( &g_EventList.m_Memory.m_pMemory[v4] != nullptr )
      return 0;
  }
LABEL_7:
  EventList_AddEventEntry(pName: pszEventName, iEventIndex, isPrivate: false, iType);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100D2850
// Name: enum Animevent EventList_RegisterPrivateEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_RegisterPrivateEvent(const char *pszEventName)
{
  int StringID; // eax
  eventlist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && (v2 = &g_EventList.m_Memory.m_pMemory[StringID]) != nullptr )
  {
    if ( v2->isPrivate == 0 )
    {
      _Warning(a1: "***\nShared<->Private Event collision!\n***\n");
      return -1;
    }
  }
  else
  {
    v2 = EventList_AddEventEntry(pName: pszEventName, iEventIndex: g_HighestEvent + 1, isPrivate: true, iType: 16);
  }
  return v2->eventIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100D28B0
// Name: void EventList_RegisterSharedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_RegisterSharedEvents()
{
  EventList_RegisterSharedEvent(pszEventName: "AE_EMPTY", iEventIndex: 0, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_LEFTFOOT", iEventIndex: 1, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RIGHTFOOT", iEventIndex: 2, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_BODYDROP_LIGHT", iEventIndex: 3, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_BODYDROP_HEAVY", iEventIndex: 4, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_SWISHSOUND", iEventIndex: 5, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_180TURN", iEventIndex: 6, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ITEM_PICKUP", iEventIndex: 7, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_DROP", iEventIndex: 8, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_SEQUENCE_NAME", iEventIndex: 9, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_SEQUENCE_NUMBER", iEventIndex: 10, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_ACTIVITY", iEventIndex: 11, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_HOLSTER", iEventIndex: 12, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_DRAW", iEventIndex: 13, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_FIRE", iEventIndex: 14, iType: 9);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_PLAYSOUND", iEventIndex: 15, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_SV_PLAYSOUND", iEventIndex: 16, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_STOPSOUND", iEventIndex: 17, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_START_SCRIPTED_EFFECT", iEventIndex: 18, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_STOP_SCRIPTED_EFFECT", iEventIndex: 19, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CLIENT_EFFECT_ATTACH", iEventIndex: 20, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MUZZLEFLASH", iEventIndex: 21, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_MUZZLEFLASH", iEventIndex: 22, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_THUMPER_THUMP", iEventIndex: 23, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_AMMOCRATE_PICKUP_AMMO", iEventIndex: 24, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RAGDOLL", iEventIndex: 25, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ADDGESTURE", iEventIndex: 26, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RESTARTGESTURE", iEventIndex: 27, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ATTACK_BROADCAST", iEventIndex: 28, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_HURT_INTERACTION_PARTNER", iEventIndex: 29, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_SET_INTERACTION_CANTDIE", iEventIndex: 30, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_SV_DUSTTRAIL", iEventIndex: 31, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_CREATE_PARTICLE_EFFECT", iEventIndex: 32, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_STOP_PARTICLE_EFFECT", iEventIndex: 33, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_ADD_PARTICLE_EFFECT_CP", iEventIndex: 34, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_CREATE_PARTICLE_BRASS", iEventIndex: 35, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_RAGDOLL", iEventIndex: 36, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_ENABLE_BODYGROUP", iEventIndex: 37, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_DISABLE_BODYGROUP", iEventIndex: 38, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_BODYGROUP_SET_VALUE", iEventIndex: 39, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_BODYGROUP_SET_VALUE_CMODEL_WPN", iEventIndex: 40, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_PRIMARYATTACK", iEventIndex: 41, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_INCREMENTAMMO", iEventIndex: 42, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_HIDE", iEventIndex: 43, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_UNHIDE", iEventIndex: 44, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_ASW_FOOTSTEP", iEventIndex: 46, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_FOOTSTEP", iEventIndex: 47, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_A", iEventIndex: 48, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_B", iEventIndex: 49, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_C", iEventIndex: 50, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_REMOVE_CLIENT_AIM", iEventIndex: 51, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_PLAYWPNSOUND", iEventIndex: 45, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_DAMAGE", iEventIndex: 52, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_START_COLLISION_DAMAGE", iEventIndex: 53, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_STOP_COLLISION_DAMAGE", iEventIndex: 54, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_SCREEN_SHAKE", iEventIndex: 55, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_START_DETECTING_COMBO", iEventIndex: 56, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_STOP_DETECTING_COMBO", iEventIndex: 57, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_COMBO_TRANSITION", iEventIndex: 58, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_ALLOW_MOVEMENT", iEventIndex: 59, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_SKILL_EVENT", iEventIndex: 60, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_TUG_INCAP", iEventIndex: 61, iType: 1);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10121850
// Name: void EventList_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_Init()
{
  g_HighestEvent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10121860
// Name: int EventList_GetEventType(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_GetEventType(int eventIndex)
{
  int v1; // eax
  eventlist_t *i; // ecx
  eventlist_t *v4; // eax

  v1 = 0;
  if ( g_EventList.m_Size <= 0 )
    return -1;
  for ( i = g_EventList.m_Memory.m_pMemory; i->eventIndex != eventIndex; ++i )
  {
    if ( ++v1 >= g_EventList.m_Size )
      return -1;
  }
  v4 = &g_EventList.m_Memory.m_pMemory[v1];
  if ( v4 != nullptr )
    return v4->iType;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101218B0
// Name: int EventList_IndexForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_IndexForName(const char *pszEventName)
{
  int StringID; // eax
  eventlist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && (v2 = &g_EventList.m_Memory.m_pMemory[StringID]) != nullptr )
    return v2->eventIndex;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101218E0
// Name: char const __near * EventList_NameForIndex(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl EventList_NameForIndex(int eventIndex)
{
  int v1; // eax
  eventlist_t *i; // ecx
  eventlist_t *v4; // eax

  v1 = 0;
  if ( g_EventList.m_Size <= 0 )
    return nullptr;
  for ( i = g_EventList.m_Memory.m_pMemory; i->eventIndex != eventIndex; ++i )
  {
    if ( ++v1 >= g_EventList.m_Size )
      return nullptr;
  }
  v4 = &g_EventList.m_Memory.m_pMemory[v1];
  if ( v4 != nullptr )
    return CStringRegistry::GetStringForKey(this: &g_EventStrings, key: v4->stringKey);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10121930
// Name: void EventList_Free(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_Free()
{
  eventlist_t *m_pMemory; // eax

  CStringRegistry::ClearStrings(this: &g_EventStrings);
  g_EventList.m_Size = 0;
  if ( g_EventList.m_Memory.m_nGrowSize < 0 )
  {
    ++g_nEventListVersion;
    g_EventList.m_pElements = g_EventList.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_EventList.m_Memory.m_pMemory;
    if ( g_EventList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_EventList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_EventList.m_Memory.m_pMemory = nullptr;
    }
    ++g_nEventListVersion;
    g_EventList.m_Memory.m_nAllocationCount = 0;
    g_EventList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101219A0
// Name: struct eventlist_t __near * EventList_AddEventEntry(char const __near *,int,bool,int)
// Source: json
//------------------------------------------------------------------------------
eventlist_t *__cdecl EventList_AddEventEntry(const char *pName, int iEventIndex, bool isPrivate, int iType)
{
  int m_Size; // eax
  int v5; // esi
  eventlist_t *m_pMemory; // ecx
  int v7; // eax
  eventlist_t *v8; // edi
  eventlist_t *result; // eax

  m_Size = g_EventList.m_Size;
  v5 = g_EventList.m_Size;
  if ( g_EventList.m_Size + 1 > g_EventList.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&g_EventList,
      num: g_EventList.m_Size - g_EventList.m_Memory.m_nAllocationCount + 1);
    m_Size = g_EventList.m_Size;
  }
  m_pMemory = g_EventList.m_Memory.m_pMemory;
  g_EventList.m_Size = m_Size + 1;
  v7 = m_Size - v5;
  g_EventList.m_pElements = g_EventList.m_Memory.m_pMemory;
  if ( v7 > 0 )
  {
    _V_memmove(dest: &g_EventList.m_Memory.m_pMemory[v5 + 1], src: &g_EventList.m_Memory.m_pMemory[v5], count: 12 * v7);
    m_pMemory = g_EventList.m_Memory.m_pMemory;
  }
  v8 = &m_pMemory[v5];
  v8->eventIndex = iEventIndex;
  v8->stringKey = CStringRegistry::AddString(this: &g_EventStrings, stringText: pName, stringID: v5);
  v8->isPrivate = isPrivate;
  v8->iType = iType;
  result = v8;
  if ( iEventIndex > g_HighestEvent )
    g_HighestEvent = iEventIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10121A50
// Name: bool EventList_RegisterSharedEvent(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl EventList_RegisterSharedEvent(const char *pszEventName, int iEventIndex, int iType)
{
  int StringID; // eax
  int v4; // eax
  eventlist_t *m_pMemory; // ecx

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && &g_EventList.m_Memory.m_pMemory[StringID] != nullptr )
    return 0;
  v4 = 0;
  if ( g_EventList.m_Size > 0 )
  {
    m_pMemory = g_EventList.m_Memory.m_pMemory;
    while ( m_pMemory->eventIndex != iEventIndex )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= g_EventList.m_Size )
        goto LABEL_7;
    }
    if ( &g_EventList.m_Memory.m_pMemory[v4] != nullptr )
      return 0;
  }
LABEL_7:
  EventList_AddEventEntry(pName: pszEventName, iEventIndex, isPrivate: false, iType);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10121AD0
// Name: enum Animevent EventList_RegisterPrivateEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl EventList_RegisterPrivateEvent(const char *pszEventName)
{
  int StringID; // eax
  eventlist_t *v2; // eax

  StringID = CStringRegistry::GetStringID(this: &g_EventStrings, stringText: pszEventName);
  if ( StringID >= 0 && (v2 = &g_EventList.m_Memory.m_pMemory[StringID]) != nullptr )
  {
    if ( v2->isPrivate == 0 )
    {
      _Warning(a1: "***\nShared<->Private Event collision!\n***\n");
      return -1;
    }
  }
  else
  {
    v2 = EventList_AddEventEntry(pName: pszEventName, iEventIndex: g_HighestEvent + 1, isPrivate: true, iType: 1);
  }
  return v2->eventIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10121B30
// Name: void EventList_RegisterSharedEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EventList_RegisterSharedEvents()
{
  EventList_RegisterSharedEvent(pszEventName: "AE_EMPTY", iEventIndex: 0, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_LEFTFOOT", iEventIndex: 1, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RIGHTFOOT", iEventIndex: 2, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_BODYDROP_LIGHT", iEventIndex: 3, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_BODYDROP_HEAVY", iEventIndex: 4, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_SWISHSOUND", iEventIndex: 5, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_180TURN", iEventIndex: 6, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ITEM_PICKUP", iEventIndex: 7, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_DROP", iEventIndex: 8, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_SEQUENCE_NAME", iEventIndex: 9, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_SEQUENCE_NUMBER", iEventIndex: 10, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_SET_ACTIVITY", iEventIndex: 11, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_HOLSTER", iEventIndex: 12, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_DRAW", iEventIndex: 13, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_WEAPON_FIRE", iEventIndex: 14, iType: 9);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_PLAYSOUND", iEventIndex: 15, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_SV_PLAYSOUND", iEventIndex: 16, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_STOPSOUND", iEventIndex: 17, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_START_SCRIPTED_EFFECT", iEventIndex: 18, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_STOP_SCRIPTED_EFFECT", iEventIndex: 19, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CLIENT_EFFECT_ATTACH", iEventIndex: 20, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MUZZLEFLASH", iEventIndex: 21, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_MUZZLEFLASH", iEventIndex: 22, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_THUMPER_THUMP", iEventIndex: 23, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_AMMOCRATE_PICKUP_AMMO", iEventIndex: 24, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RAGDOLL", iEventIndex: 25, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ADDGESTURE", iEventIndex: 26, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_RESTARTGESTURE", iEventIndex: 27, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_ATTACK_BROADCAST", iEventIndex: 28, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_HURT_INTERACTION_PARTNER", iEventIndex: 29, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_NPC_SET_INTERACTION_CANTDIE", iEventIndex: 30, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_SV_DUSTTRAIL", iEventIndex: 31, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_CREATE_PARTICLE_EFFECT", iEventIndex: 32, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_STOP_PARTICLE_EFFECT", iEventIndex: 33, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_ADD_PARTICLE_EFFECT_CP", iEventIndex: 34, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_CREATE_PARTICLE_BRASS", iEventIndex: 35, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_RAGDOLL", iEventIndex: 36, iType: 1);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_ENABLE_BODYGROUP", iEventIndex: 37, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_DISABLE_BODYGROUP", iEventIndex: 38, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_BODYGROUP_SET_VALUE", iEventIndex: 39, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_CL_BODYGROUP_SET_VALUE_CMODEL_WPN", iEventIndex: 40, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_PRIMARYATTACK", iEventIndex: 41, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_INCREMENTAMMO", iEventIndex: 42, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_HIDE", iEventIndex: 43, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_UNHIDE", iEventIndex: 44, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_ASW_FOOTSTEP", iEventIndex: 46, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_FOOTSTEP", iEventIndex: 47, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_A", iEventIndex: 48, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_B", iEventIndex: 49, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_MARINE_RELOAD_SOUND_C", iEventIndex: 50, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_REMOVE_CLIENT_AIM", iEventIndex: 51, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_WPN_PLAYWPNSOUND", iEventIndex: 45, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_DAMAGE", iEventIndex: 52, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_START_COLLISION_DAMAGE", iEventIndex: 53, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_MELEE_STOP_COLLISION_DAMAGE", iEventIndex: 54, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_SCREEN_SHAKE", iEventIndex: 55, iType: 16);
  EventList_RegisterSharedEvent(pszEventName: "AE_START_DETECTING_COMBO", iEventIndex: 56, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_STOP_DETECTING_COMBO", iEventIndex: 57, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_COMBO_TRANSITION", iEventIndex: 58, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_ALLOW_MOVEMENT", iEventIndex: 59, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_SKILL_EVENT", iEventIndex: 60, iType: 17);
  EventList_RegisterSharedEvent(pszEventName: "AE_TUG_INCAP", iEventIndex: 61, iType: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10400C10
// Name: _dynamic_initializer_for__event_queue_saveload_proxy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__event_queue_saveload_proxy__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEventQueueSaveLoadProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &event_queue_saveload_proxy,
           a3: "event_queue_saveload_proxy");
}

//------------------------------------------------------------------------------
// Address: 0x10400C30
// Name: _dynamic_initializer_for__dumpeventqueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dumpeventqueue__()
{
  ConCommand::ConCommand(
    this: &dumpeventqueue,
    pName: "dumpeventqueue",
    callback: CC_DumpEventQueue,
    pHelpString: "Dump the contents of the Entity I/O event queue to the console.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__dumpeventqueue__);
}

} // namespace server
